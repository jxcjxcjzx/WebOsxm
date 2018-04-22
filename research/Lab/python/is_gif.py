#  codes to judge gif file

def is_gif(fname):
	f=open(fname,'br')
	first4=tuple(f.read(4))
	return first4==(0x47,0x49,0x46,0x38)   # judge by the first 4 bytearray
	
