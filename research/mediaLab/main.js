var http = require('http');
var fs = require('fs');
var url = require('url');

http.createServer(function(req,res){

// judge from the request url information
var tmp = req.url;
var params = url.parse(tmp);

if(params.query == 'movie')   // push the index html page
{
	    res.writeHead(200,{'Content-Type':'text/html'});
		res.write(fs.readFileSync("one_possible_videopush_solution.html"));
		res.end("the end");
		console.log("jumped into there");
}
	
}
).listen(1773);
console.log('Server running at http://you know the ip:1773/?movie');