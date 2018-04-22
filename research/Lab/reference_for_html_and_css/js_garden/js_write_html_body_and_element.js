// write html body and element demo

var body = '<html>'+'<head>'+'<body>'+'<form action="/upload" method="post">'+'<textarea name="text" rows="20" cols="50"></textarea>'+'<input type="submit" value="submit"/>'+'</form></body></html>';

response.writeHead(200,{"Content-Type":"text/html"});

response.write(body);

response.end();