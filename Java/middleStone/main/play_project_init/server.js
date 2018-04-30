var app = require('http').createServer(handler), 
    io = require('socket.io').listen(app), 
    fs = require('fs')

app.listen(8080);

var outer_socket  ;

function handler (req, res) {
  fs.readFile(__dirname + '/index.html',function (err, data) {  
    if (err) {
      res.writeHead(500);
      return res.end('Error loading index.html');
    }    
    res.writeHead(200, {'Content-Type': 'text/html'});    
    res.end(data);
  });
}

io.sockets.on('connection', function (socket) {
    socket.emit('news', { hello: 'world' });
    socket.on('my other event', function (data) {
      console.log(data);
    });
	
	outer_socket = socket;

});

var interval= setInterval(function() { 
		outer_socket.emit('news', { hello: 'world' });
		},5000);

