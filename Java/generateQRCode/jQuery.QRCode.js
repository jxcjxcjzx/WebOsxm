// reference from jquery-qrcode , thks to jeromeetienne

(function($){ 
	$.fn.qrcode = function(options){
		// if option is a string 
		
		console.log(" Hi, go into execution ! ");
		
		if(typeof options === 'string'){
			options = {text:options};
		}
		// set defaults 
		options = $.extend({},{
			render  : "canvas",
			width   : 256,
			height   :256,
			typeNumber   :-1,
			correctLevel:   QRErrorCorrectLevel.H,
			background   :  "#ffffff",
			foreground   :  "#000000"
		
		},options);
		
		var createCanvas = function(){
			// create the qrcode 
			var qrcode = new QRCode(options.typeNumber,options.correctLevel);
			qrcode.addData(options.text);
			qrcode.make();
			
			// create the canvas element 
			var canvas = document.createElement('canvas');
			canvas.width = options.width;
			canvas.height = options.height;
			var ctx  = canvas.getContext('2d');
			
			// do some simple compute 
			// the getModuleCount is a bit ambigulous, change it later 
			var tileW = options.width/qrcode.getModuleCount();
			var tileH = options.height/qrcode.getModuleCount();
			
			// draw in the canvas
			for(var row = 0;row<qrcode.getModuleCount();row++){
				for(var col = 0;col<qrcode.getModuleCount();col++){
					ctx.fillStyle = qrcode.isDark(row,col)?options.foreground:options.background;
					var w = (Math.ceil((col+1)*tileW)-Math.floor(col*tileW));
					var h = (Math.ceil((row+1)*tileH)-Math.floor(row*tileW));
					ctx.fillRect(Math.round(col*tileW),Math.round(row*tileH),w,h);
				}			
			}
			
			return canvas;
		}
		
		var createTable = function(){
			// did not quite get what the correctLevel means 
			var qrcode = new QRCode(options.typeNumber,options.correctLevel);
			qrcode.addData(options.text);
			qrcode.make();
			
			// create the table element 
			var $table = $('<table></table>')
			.css("width",options.width+"px")
			.css("height",options.height+"px")
			.css("border","0px")
			.css("border-collapse","collapse")
			.css("background-color",options.background);
			
			// compute tileS percentage 
			var tileW = options.width/qrcode.getModuleCount();
			var tileH = options.height/qrcode.getModuleCount();
			
			// draw in table 
			for(var row = 0;row<qrcode.getModuleCount();row++){
				var $row = $('<tr></tr>').css('height',tileH+"px").appendTo($table);
				
				for(var col=0;col<qrcode.getModuleCount();col++){
					$('<td></td>')
						.css('width',tileW+"px")
						.css('background-color',qrcode.isDark(row,col)?options.foreground:options.background)   // can dod some youhua here , if only use canvas 
						.appendTo($row);
				}
			}
			
			return $table;
		}
		
		return this.each(function(){
			var element = options.render =="canvas"?createCanvas():createTable();
			$(element).appendTo(this);
		});
	};
})(jQuery);