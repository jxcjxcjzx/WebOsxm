# python file for print file


def print_file1(fname)
	f = open(fname,'r')
	for line in f:
		print(line,end='')
	f.close()  # this line is choosable

def print_file2(fname)
	f = open(fname,'r')
	print(f.read())
	f.close()
	
