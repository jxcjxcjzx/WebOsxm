// this is a test js file to see how the 
// html page code will render and perform

var http = require('http');
var fs = require('fs');
var url = require('url');
var path = require('path');
var tmp_safepicname = "template.png";


// var for handle post data
var  postDataHandle = require('./postDataHandle.js');


var pngfile_syntax = ".png";
var jpgfile_syntax = ".jpg";


function FileExist(fPath)
{ 
     
}

function handle()
{

}

// picture nname check
function legal_name_check(picname)
{
	
	if(fs.existsSync(picname)){
		if(path.extname(picname)== jpgfile_syntax|| path.extname(picname)== pngfile_syntax)
		{
			// passed the check 
			return picname;
		}
		else{
			return tmp_safepicname;
		}
	
	}

}


function getPicNameListInDir(dir)
{
	

}

function thubmNailPics()
{
	
	
}



http.createServer(function(req,res){

	// prepare for the safe html file first
	if(!fs.existsSync(tmp_safepicname))
	{
	 // then create it automatically
		console.log("file not exist , sorry ");
	}

	// just for debug
	console.log(req.url);

	// console.log(req);
	
	// judge from the request url information
	var requesturl = req.url;
	var params = url.parse(requesturl);
	var pathname = params.pathname; 
	var ext = pathname.match(/(\.[^.]+|)$/)[0];//取得后缀名 
	
	// now starts handle the post request
	// set the encoding method 
	/*
	
	var postData = "";
	req.setEncoding("utf-8");
	req.addListener("data",function(data){
		postData+=data;
	}
	);
	// maybe the client want a bunch of pictures, so handle the post and fullfill their request
	req.addListener("end",function(){
	
		// use outside js code to handle this post data
		postDataHandle.obtain(postData);
		postDataHandle.popDetails();
		// one more thing 
		handle();
		
	});
	
	*/
	
	switch(ext){	 
		// first three media pushes
		// too much options , separate them all
		case ".jpg": 
		fs.readFile("."+requesturl,function (err, data) {//读取内容 
			if (err) throw err; 
			res.writeHead(200,{'Content-Type':'image/jpg'});
			res.write(data);
			res.end(); 
		});
		
		break;
		
		case ".png": 
		fs.readFile("."+requesturl,function (err, data) {//读取内容 
			if (err) throw err; 
			res.writeHead(200,{'Content-Type':'image/png'});
			res.write(data);
			res.end(); 
		});
		
		break;		
		
		break;
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
		fs.readFile("."+requesturl,function (err, data) {//读取内容 
			if (err) throw err; 
			res.writeHead(200, {'Content-Type':'application/javascript'}); 
			res.write(data); 
			res.end(); 
		});
		break;
		default:
		
			if(params.query.startsWith( 'whereis' ))   // push the index html page
			{	
					// deal with picname combination query
					
			}	
			
			if(params.query.startsWith( 'nameListin' ))   // push the index html page
			{	
					// grep all pictures in one specified dir 
			}	
		
		
			if(params.query == 'testit')   // push the index html page
			{	
					res.writeHead(200,{'Content-Type':'image/png'});
					res.write(fs.readFileSync(legal_name_check(tmp_safepicname)));
					res.end();
			}	
			// only for test purpose
			if(params.query == 'testUniverse')   // push the index html page
			{	
					
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
  }
).listen(1111);
console.log('Server running at http://you know the ip:1111/?PicUniverse');