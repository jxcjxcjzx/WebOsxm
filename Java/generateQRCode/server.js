// simple file operation
var fs = require('fs');
 
// var encoder = require('punycode');

// find the place of files
var path = require('path');

// server side about
var http = require('http');
var url = require('url');

// use the linux system tool --- the 'ls' and 'head' command

var util = require('util');

// we do not need the pic name argument, cause we have 
// it in the json file ahead already
// .........:)


var HtmlSrc = "";

var httpServer;

// simple functional test
// write image only if the url request for only images, (tip: see the format)
function htmlpush_server(string_to_generate_QRCode){

		HtmlSrc = "<!DOCTYPE html><html><head><title>  Demo </title></head><body><p> write something here  2 </p><div id=\"output\"></div ><script type = \"text/javascript\" src = '../../../res/js/jquery.min.js'></script><script type = \"text/javascript\" src = './jQuery.QRCode.js'></script><script type = \"text/javascript\" src = \"./QRCode.js\">"+"</script><script>jQuery(function(){jQuery('#output').qrcode(\""+string_to_generate_QRCode+"\");})</script></body></html>";

		if(httpServer==null){
			httpServer = http.createServer(function(req,res){

				// judge from the request url information
				var requesturl = req.url;
				var params = url.parse(requesturl);
				var pathname = params.pathname; 
				var htmlname = "./demo.html";
				
				var ext = pathname.match(/(\.[^.]+|)$/)[0];//取得后缀名 
				
				// serve the js and css files if needed 
				switch(ext){	 
					// first three media pushes
					// too much options , separate them all
					case ".css":  
					  // push the css file
					  fs.readFile("."+requesturl,function (err, data) {//读取内容 
						if (err) throw err; 
						res.writeHead(200, {'Content-Type':'text/css'}); 
						res.write(data); 
						res.end(); 
					});
					break;
					
					
					case ".js":
					// adjust the js file supply strategy 
					fs.readFile("."+pathname,function (err, data) {//读取内容 
						if (err) throw err; 
						res.writeHead(200, {'Content-Type':'application/javascript'}); 
						res.write(data); 
						res.end(); 
					});
					break;
				}

				if(params.query == 'QRCode')
				{
				// push the image to the client side
				// here we have to first generate the needed image name, or 
				// in other words, pick up a pic randomly

					// actually we have two kinds of pictures , jpg and png format
					res.writeHead(200,{'Content-Type':'text/html'});

					// testing point
					// console.log('the chosen html name is : '+htmlname);
					
					// do some judgement here 

					 {
						// res.write(fs.readFileSync(htmlname));
						// directly write in the data
						res.write(HtmlSrc);
						
						res.end('html sent...., with name of '+htmlname+' :)');
					}
					
					var response = true;
					if(response){
						// after one success response , return and release the port 
						//httpServer.close();
					}
					
					return false ;
					
				}

				}

			);
		}
		
		httpServer.listen(1337);
		
		console.log('Server running at http://you know the ip:1337/');

}


module.exports = {

	htmlpush_server : htmlpush_server
}