# python tool for download web pages
# or just another saying, download the world wide web

import httplib  
import urllib  
import sys  

def downloadDemo():
	url = 'http://www.eet-china.com/'  
	urllib.urlretrieve(url, "D:\\electronic.html")   

	# another way to download the same file
	#f = urllib2.urlopen(url) 
	#data = f.read() 
	#with open("code2.zip", "wb") as code:     
	#	code.write(data)  

	# yet another way to download, again the same file
	#r = requests.get(url) 
	#with open("code3.zip", "wb") as code:
	#	code.write(r.content)
		
if __name__ == '__main__':
	downloadDemo()