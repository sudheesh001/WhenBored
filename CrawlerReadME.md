To use the crawler, go to your command line (Dude .... , I KNOW!) and type 

python cmcrawler.py http://www.siteurl.com [crawl external]

Replace [crawl external] with a 0 if you just want to crawl internal URLs, or 1 if you want to crawl external, too.

It'll then cheerfully go off and start crawling your site, outputting the result as it goes. It doesn't save the output anywhere! You can cut-and-paste the result if you're really insane, or do the easier:

python cmcrawler.py http://www.siteurl.com [crawl external] >> filename.txt

That'll write the results to a text file, instead.

If none of this makes sense to you, you probably shouldn't be messing with this. I'm not saying that to be mean. 
This is a crawler that could be dangerous.
 
As such, you should be very, very careful with it.

FILE YOU ISSUES TO GITHUB. or mail them over to

sudheesh1995@outlook.com
