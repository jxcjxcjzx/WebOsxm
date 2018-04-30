#  python tool for thumbnail generating

from PIL import Image
import os


rate = 40
resizedAddone = 'resized_'
supportFormat = ['bmp','gif','jpg','png']

		

def makeThumb(path):	
	fileExt = os.path.splitext(path)[1].lower()[1:]
	if fileExt in supportFormat:
		img = Image.open(path)
		img.thumbnail((img.size[0]*rate/100,img.size[1]*rate/100))
		img.save(resizedAddone+str(rate)+'_'+os.path.basename(path))
	
	
if __name__ == '__main__':
	makeThumb("F:\\Pictures\\test.png")
	
	
	
