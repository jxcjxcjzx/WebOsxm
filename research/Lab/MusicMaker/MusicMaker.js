// one simple music maker server, 
// will merge into the main server later

// this is a test js file to see how the 
// html page code will render and perform

var http = require('http');
var fs = require('fs');
var url = require('url');
var path = require('path');

// to store the music maker data
var arr = ['start'];


function handle()
{

}

Array.prototype.push=function()
{
	var len=arguments.length;
	if(len>0)
		for(var i=0;i<len;i++)
			this[this.length]=arguments[i];
		
	return this.length;
}



 String.prototype.startWith=function(s){
  if(s==null||s==""||this.length==0||s.length>this.length)
   return false;
  if(this.substr(0,s.length)==s)
     return true;
  else
     return false;
  return true;
 }




http.createServer(function(req,res){

	

			// just for debug
			console.log(req.url);

			// console.log(req);
			
			// judge from the request url information
			var requesturl = req.url;
			var params = url.parse(requesturl);
			// to store the music maker data
			

	
	// here the main job the music maker server does is to record the time when 
	// switch happens
	// will post a standard for this music stop later
	
			if(params.query.startWith('record'))   // push the index html page
			{	
					// do some data store here, and finally write them all into a 
					// file for later use when play music
					console.log("record received!");
					
					// record the switch point, parsed from the url
				//	res.writeHead(200,{'Content-Type':'text/plain'});
				//	res.write("ok, get it");
				//	res.end();
					
					// now get the data needed 
					
					if(arr.push(params.query)>4){
						// then write in the data
						console.log("beginning to write in the data, arr is : "+arr);
						var  outFileName = "stop_data.stop";
						// do the file saving operation
						fs.writeFile(outFileName,arr,function(err){
							// do err handling
						
						});
					}
					
			}	
			
			
			
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
	}
).listen(1777);
console.log('Server running at http://you know the ip:1777/?record+switch+from+to+end');