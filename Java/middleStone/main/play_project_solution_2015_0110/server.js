var ws = require("nodejs-websocket");
console.log("开始建立连接...")
 

// only for test 
var play_conn1;
var play_conn2;
var play_conn3;
var play_conn4;
// end of test area
 
var game1 = null,game2 = null , game1Ready = false , game2Ready = false;
var server = ws.createServer(function(conn){
    conn.on("text", function (str) {
        console.log("收到的信息为:"+str)
		/*       
		   if(str==="game1"){
				game1 = conn;
				game1Ready = true;
				conn.sendText("success");
			}
			if(str==="game2"){
				game2 = conn;
				game2Ready = true;
			}
	 
			if(game1Ready&&game2Ready){
				game2.sendText(str);
			}
			
			if(str==="game2"){
				game2 = conn;
				game2Ready = true;
			}
		*/
 
       // conn.sendText(str)
	   // maximaze of 4 players
	   if(str==="player1"){
            play_conn1 = conn;   
			play_conn1.sendText(str);			
        }
		if(str==="player2"){
            play_conn2 = conn;
			play_conn2.sendText(str);			
        }
		if(str==="player3"){
            play_conn3 = conn;     
			play_conn3.sendText(str);						
        }
		if(str==="player4"){
            play_conn4 = conn;     
			play_conn4.sendText(str);						
        }
	   
    })
    conn.on("close", function (code, reason) {
        console.log("关闭连接")
    });
    conn.on("error", function (code, reason) {
        console.log("异常关闭")
    });
	
	// out_conn = conn;
	
}).listen(8001);

// for bluetooth music , ahead 2 seconds
var interval= setInterval(function() { 
		play_conn1.sendText('play');
		},19700);
		
var interval= setInterval(function() { 
		play_conn2.sendText('play');
		},20300);
		

var interval= setInterval(function() { 
		play_conn3.sendText('play');
		},20000);
		
var interval= setInterval(function() { 
		play_conn4.sendText('play');
		},20500);

console.log("WebSocket service constructed")