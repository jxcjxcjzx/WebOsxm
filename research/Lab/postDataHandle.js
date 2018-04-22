// js post data handle


// for handle query string
var querystring = require("querystring") ;  

var publicPostData = "";

exports.obtain = obtain;
exports.popDetails = popDetails;
exports.popRaw = popRaw;

function obtain(postData)
{
	
	// copy to the public data
	copytData(postData);

}

function copytData(src)
{

	// tmp realization
	publicPostData = src;

}

function popRaw()
{

	if(publicPostData==""){
		console.log("POST data is empty in popRaw!");
	}
	// do some error checking here
		var params = querystring.parse(publicPostData);//GET & POST	
		return params;
	
}

function popDetails()
{
	if(publicPostData=="")
	{
		// did not receive the data here
		console.log("POST data is empty in detail!");
	}
	else
	{
	
		// parse the data
		var params = querystring.parse(publicPostData);//GET & POST
		
		// test data parsing
        console.log(params);
		console.log("first issue to solve : "+params["title"][1]);
		
	}


}