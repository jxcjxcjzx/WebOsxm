// this is compute.js file, do some simple computing work

var i=0;

function timeCount(){
	for(var j=0,sum=0;j<100;j++){
		for(var i=0;i<10000;i++){
			sum+=i;
		}
	}
	
	postMessage(sum);

}

postMessage("Before computing,"+new Date());
timeCount();
postMessage("After computing,"+new Date());