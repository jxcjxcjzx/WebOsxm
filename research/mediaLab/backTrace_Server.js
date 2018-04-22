//  the back trace server
//  a new way to interfere with multi-worker situations

// the js time server
// this is a test js file to see how the 
// html page code will render and perform

var http = require('http');
var fs = require('fs');
var url = require('url');
var path = require('path');


function handle()
{

}

function js_backTraceCaught()
{
	// do things here cause call back occurs
	// ......
	
}




http.createServer(function(req,res){

			// this server only response to time request
			
			// just for debug
			console.log(req.url);

			// console.log(req);
			
			// judge from the request url information
			var requesturl = req.url;
			var params = url.parse(requesturl);
			
			// now starts handle the post request
			// set the encoding method 
			
			var postData = "";
			req.setEncoding("utf-8");
			req.addListener("data",function(data){
				postData+=data;
				console.log("Received POST data :"+data);
			}
			);
			req.addListener("end",function(){
				handle();
			
			});
	

			if(params.query == 'callBackCall')   // push the index html page
			{	
			// call back happens here
					js_backTraceCaught();
					// only for debug
					console.log('call back happens');
			}	
			
			
			/*
			if(params.query == 'reboot')   // push the index html page
			{	
					// here we provide a trick to restart the server
					// developers are allowed to modify the server 
					// functionality codes before restarting it.:)
					// actually before restart you can modify the code in this server to achieve the efficient goal :)
					
					// actually when rebooting server did return something, but the client just won't receive, check this.
					res.writeHead(200,{'Content-Type':'text/plain'});
					res.write('rebooting ..... wait a minute :) ');
					res.end();
					
					thislineofcodejustdoesnotworkfornodejssorry
			}	
			*/
	
  }
).listen(1339);
console.log('Server running at http://you know the ip:1339/?callBackCall');