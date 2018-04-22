# python write file codes

def make_story1():
	f = open('story.txt','w')
	f.write('write something...')
	
def make_story2():
	if os.path.isfile('story.txt');
		print('exist')
	else	
		f = open('story.txt','w')
		f.write('write something...')

		
def add_to_story(line,fname='story.txt'):
	f = open(fname,'a')
	f.write(line)
	
	
def insert_title(title,fname='story.txt'):
	f=open(fname,'r+')
	temp=f.read()
	temp = title+'\n\n'+temp
	f.seek(0)  # move pointer to head of file
	f.write(temp)
	
