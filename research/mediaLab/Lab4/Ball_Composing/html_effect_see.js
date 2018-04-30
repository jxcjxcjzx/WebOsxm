// this is a test js file to see how the 
// html page code will render and perform

var http = require('http');
var fs = require('fs');
var url = require('url');
var path = require('path');
var tmp_safehtmlname = "template.html";


// var for handle post data
var  postDataHandle = require('./postDataHandle.js');

var test_html_file_name = "BallThing.html";

// only for test purpose
var middlestone_html_file_name = "game2.html";
var music_channel1 = "player1.html";
var music_channel2 = "player2.html";
var music_channel3 = "player3.html";

// end of test area 

var htmlfile_syntax = ".html";
var htmlfile_syntax_optional = ".htm";



function FileExist(fPath)
{ 
     
}

function handle()
{

}


// function to check if the html name exists and contains the '.html' suffix
function legal_name_check(htmlname)
{
	if(fs.existsSync(htmlname))
	{	
		if(path.extname(htmlname)== htmlfile_syntax)
		{
			// passed the check 
			return htmlname;
		}
	}
	else{
		return tmp_safehtmlname;
	}
	
}




http.createServer(function(req,res){

	// prepare for the safe html file first
	if(!fs.existsSync(tmp_safehtmlname))
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
		
		
		case ".mp3": 
		// for test reason
		console.log("resource addr is : "+requesturl);
		fs.readFile("."+requesturl,function (err, data) {//读取内容 
			if (err) throw err; 
			res.writeHead(200,{'Content-Type':'media/mp3'});
			res.write(data);
			res.end(); 
		});
		
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
		// added  2015.01.1337
		case ".pdf":  
		  // push the pdf file
		  fs.readFile("."+requesturl,function (err, data) {//读取内容 
			if (err) throw err; 
			res.writeHead(200, {'Content-Type':'application/pdf'}); 
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
			if(params.query == 'testit')   // push the index html page
			{	
					res.writeHead(200,{'Content-Type':'text/html'});
					res.write(fs.readFileSync(legal_name_check(test_html_file_name)));
					res.end();
			}	
			// only for test purpose
			if(params.query == 'testmiddlestone')   // push the index html page
			{	
					res.writeHead(200,{'Content-Type':'text/html'});
					res.write(fs.readFileSync(legal_name_check(middlestone_html_file_name)));
					res.end();
			}
			
			// a bunch of test area
			if(params.query == 'player1')   // push the index html page
			{	
					res.writeHead(200,{'Content-Type':'text/html'});
					res.write(fs.readFileSync(legal_name_check(music_channel1)));
					res.end();
			}
			if(params.query == 'player2')   // push the index html page
			{	
					res.writeHead(200,{'Content-Type':'text/html'});
					res.write(fs.readFileSync(legal_name_check(music_channel2)));
					res.end();
			}
			if(params.query == 'player3')   // push the index html page
			{	
					res.writeHead(200,{'Content-Type':'text/html'});
					res.write(fs.readFileSync(legal_name_check(music_channel3)));
					res.end();
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
).listen(1337);
console.log('Server running at http://you know the ip:1337/?testit');