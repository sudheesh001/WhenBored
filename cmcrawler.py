import sys
import httplib
import urllib2
import urlparse
import string
from bs4 import BeautifulSoup, SoupStrainer
from time import gmtime, strftime, time


def getPage(root,link):
	#does all the dirty work re: finding the page in the URL
	#more like a silly thing to do :P
	#Bla Bla, read on...
	parsedUrl = urlparse.urlparse(link)
	site = parsedUrl.netloc
	if (parsedUrl.query):
		page = parsedUrl.path + '?' + parsedUrl.query
	else:
		page = parsedUrl.path
	if (page == root):
		page = "/"
		site = root
	if (site == ''):
		site = root
	if (site != root):
		external = 1
	else:
		external = 0
	return link, site, page, external

def fixPage(page):
	#tests to make sure page starts with "/"
	test = page.find("/",0,1)
	if (test == -1):
		page = "/" + page
	return page


print "start time ",strftime("%a, %d %b %Y %H:%M:%S +0000", gmtime()),"\n\n\n"
#ignore this if you don't even want it.
try:
	root = sys.argv[1]
	outside = sys.argv[2]
except IndexError:
    print "  Usage: ./bscrawler.py link [crawl external = 0 or 1]"
    print "  Example: ./bscrawler.py www.google.com/ 1"
    exit()

linkz = []
crawled = []
imgz = []
counter = 0
start = time() #Starting time counter !! EXCITING :D
result=0 #Ya ya boring initializer.
parsedRoot = urlparse.urlparse(root)

if parsedRoot.port == 80:
    hostRoot = parsedRoot.netloc[:-3]
else:
    hostRoot = parsedRoot.netloc

linkz.append(root)

imageTypes = "jpg,gif,png"
skipIt = "javascript,mailto"

# Connectivity portion of the code
for l in linkz:
	try:
		conn = httplib.HTTPConnection(root)
	
		e = getPage(root,l)
		link = e[0]
		site = e[1]
		page = e[2]
		external = e[3]
		page = fixPage(page)
		skipCheck = skipIt.find(l)
		if (outside == 1):
			skipCheck2 = 0
		else:
			if (external == 0):
				skipCheck2 = 0
			else:
				skipCheck2 = 1
		if (skipCheck == -1) & (skipCheck2 == 0):
			conn.request("GET", page)
			code = conn.getresponse() # read response code 
			src = code.read()
			src = str(src)
			flist = l.split('.')
			ftype = flist[-1]
			imageCheck = imageTypes.find(ftype)
			links = SoupStrainer('a') # grab all anchors i.e <a href= , the a tag is called anchor
			imgs = SoupStrainer('img') # grab all img elements <img src=
			if (imageCheck == -1): 
				bs = BeautifulSoup(src, parse_only=links) # parse for anchors
				if (imageCheck == -1): 
					print "Crawling\t",l,"\t",code.status
					# loop through all of the anchors found on the page
					# crawler only records the FIRST time it finds a link. If a link is on 20 pages
					# it will still only show up once in the log.
					# Ya bulky i know, make it simpler if you wish to, send in a pull request.
					for j in bs.findAll('a', {'href':True}):
						testresult = 0
						absUrl = urlparse.urljoin(l, j['href'])
						# check for javascript/mailto
						checkAbs = absUrl.split(':')
						checkAbs = checkAbs[0]
						checkAbs = checkAbs.strip()
						nskipCheck = skipIt.find(checkAbs)
						if ((nskipCheck == -1) & (absUrl.find('#') == -1)):
							absUrl = absUrl.strip()
							absUrl = absUrl.replace(' ','%20')
							e = getPage(root,absUrl)
							link = e[0]
							site = e[1]
							page = e[2]
							external = e[3]
							page = fixPage(page)
							if (outside == 1):
								skipCheck2 = 0
							else:
								if (external == 0):
									skipCheck2 = 0
								else:
									skipCheck2 = 1
							if (skipCheck2 == 0):
								try:
									if (page not in linkz):
										conn.request("GET", page)
										tcode = conn.getresponse() # read response code 
										conType = tcode.getheader("content-type")
										conTest = conType.find("text/html")
										status = str(tcode.status)
										if (status != '200'):
											print '\t' + page + '\t' + 'page' + '\t' + status + '\t'
										else:
											if (conTest == 0): # only doing pages, thank you very much
												cleanUrl = absUrl.strip()
												nimageCheck = imageTypes.find(cleanUrl)
												if (nimageCheck == -1):
													thistype = "page"
													linkz.append(page)
												else:
													thistype = "image"
												print '\t' + page + '\t' + thistype + '\t' + str(tcode.status)
												counter = counter + 1
									else:
										print '\t' + page + '\t' + thistype + '\t' + 'already crawled'
								except:
									pass		
							else:
								print '\t' + absUrl + '\t' + 'skipped external URL'
		
		# now to try to grab some images on the same page
					bsi = BeautifulSoup(src, parse_only=imgs)
					for i in bsi.findAll('img', {'src':True}):
						absUrl = urlparse.urljoin(l, i['src'])
						e = getPage(root,absUrl)
						external = e[3]
						img = e[2]
						site = e[1]
						img = fixPage(img)
						if (img not in imgz):
							conn.request("GET", img)
							tcode = conn.getresponse() # read response code 
							conType = tcode.getheader("content-type")
							if (external == 0):
								print '\t' + img + '\timage' + '\t' + str(tcode.status)
						else:
							print '\t' + img + '\timage' + '\t' + 'already crawled' 
						counter = counter + 1
						imgz.append(img)
		conn.close()
	except:
		pass


print "Completed at ",strftime("%a, %d %b %Y %H:%M:%S +0000", gmtime()),"\n\n\n",counter," urls in ", (time() - start)
# Purely optional.
# I just like a lot of information flooding across on my terminal :P if you do too, then don't comment these Started at and completed at
# Buh Bye !!!
