# the python txt writer

def list_cwd():
	return os.listdir(os.getcwd())
	
def files_cwd():
	return [p for p in listcwd()
			if os.path.isfile(p)]
			
		
def folders_cwd():
	return [p for p in listcwd()
			if os.path.isdir(p)]

			
def sized_in_bytes(fname):
	return os.stat(fname).st_size
	
def cwd_size_in_bytes():
	total = 0;
	for name in files_cwd():	
		total = total+size_in_bytes(name)
		
	return total
	

def cwd_size_in_bytes2():
	return sum(size_in_bytes(f) 
				for f in files_cwd())
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	