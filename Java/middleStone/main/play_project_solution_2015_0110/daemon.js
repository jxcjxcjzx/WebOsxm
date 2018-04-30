// this is the daemon process, responsible
// for the 'modify' and 'restart' feature for 
// the REDX server

// the lib may be needed
var child_process = require('child_process');
var worker_js_module_name = 'html_effect_see.js';

function spawn(mainProcess){
	
	var worker = child_process.spawn('node',[mainProcess]);
	worker.on('exit',function(code){
		if(0!=code){
			spawn(mainProcess);
		}
	});
}spawn(worker_js_module_name);