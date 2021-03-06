module Network.SiteCheck.Output where

import Network.Curl
import Control.Monad (when)
import Data.List (sort, group)
import System.IO

import Network.SiteCheck.Data
import Network.SiteCheck.URL

indent = "          "

printRedirects :: Link -> IO ()
printRedirects x = do
  let redirects = (previous x)
  when (not (null redirects)) $ do
    putStrLn "Redirected From: "
    mapM_ (\next -> do 
            putStrLn (indent ++ (exportURL next))) redirects

codeString :: StatusCode -> String
codeString (Code x) = show x
codeString NoCode = "None"

outputFile :: FilePath -> [Link] -> IO ()
outputFile path links = do
  handle <- openFile path WriteMode
  hPutStrLn handle "\"Parent URL\",\"URL\",\"Status\""
  mapM_ (\x -> do 
          let p = exportURL $ parent x
              url = exportURL $ theURL x
          hPutStr handle $ wrap p
          hPutStr handle ","
          hPutStr handle $ wrap url
          hPutStr handle ","
          hPutStr handle $ wrap $ codeString (status x)
          hPutStrLn handle "")
        links
  hClose handle
  where wrap x = "\"" ++ x ++ "\""

output :: Config -> [Link] -> IO ()
output config@(_, script) links = do
  let results = filterResults config $ filter (not . isRedirect) links

  putStrLn ("Checked " ++ show (length links) ++ 
            " pages in the domain " ++ (dn script) ++ ".")
  mapM_ (\x -> do 
               putStrLn ""
               putStr $ codeString (status x)
               putStrLn (" - " ++ (exportURL $ theURL x))
               putStr ("Parent: ")
               putStrLn ((exportURL $ parent x))
               printRedirects x) results
  case getResultFile (options script) of
    Just name -> outputFile name results
    Nothing -> return ()

printStack :: State -> IO ()
printStack state = do
  putStrLn ("Current Stack:")
  mapM_ (\x -> do 
          putStrLn (indent ++ x)) (stackAsStrings state)

printActions :: [Action] -> IO ()
printActions xs =
  putStrLn ("Actions: " ++ (show xs))

printPost :: String -> [CurlOption] -> IO ()
printPost url opts = do
        putStrLn "Posting: "
        putStrLn (indent ++ url ++ " -> " ++ (show opts))

printParent :: Link -> IO ()
printParent link = do
  when ((exportURL (parent link)) /= "") $ -- ugly
    putStrLn ("Parent: " ++ (exportURL (parent link)))

printStatus :: State -> URL -> IO ()
printStatus state url =
  putStr ("[" ++ (show (visitedLength state)) ++ 
          " of " ++ (show (stackLength state)) ++ "] " ++ 
          exportURL url ++ " ")

whenOpt :: Config -> Option -> IO () -> IO ()
whenOpt config opt action = do
  when (isOptionSet opt config) action

printTopStack :: State -> IO ()
printTopStack state = 
  let top = take 5 .
            reverse . sort .
            map (\g -> (length g, head g)) .
            group .
            sort .
            map (exportURL . removeParams . toURL) .
            getStack $ state
  in do
    putStrLn ("Top Stack:")
    mapM_ (\(count, url) -> do 
            putStrLn (indent ++ (show count) ++ " : " ++ url)) top

printError :: URL -> IO ()
printError url = do
  putStrLn ""
  putStrLn ("ERROR: " ++ (exportURL url))

