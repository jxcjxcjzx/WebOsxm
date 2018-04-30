import httplib

def url_open(conn_obj):
	#http long-time link
    try:
        conn_obj.request("GET", "/?callBackCall", "", {"Connection":"Keep-Alive"})
        #conn_obj.request("POST", "/func","param=0", {"Connection":"Keep-Alive"})
        response = conn_obj.getresponse()
        return response.read()
    except:
        return "error"
    
if __name__ == "__main__":
	# as a simple test, use 127.0.0.1
    conn = httplib.HTTPConnection("127.0.0.1:1339")
    
    print url_open(conn)
	
    conn.close()