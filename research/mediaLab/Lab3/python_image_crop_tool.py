#  python tool for image croping
# encoding=utf8 
from PIL import Image


import Image


def imageCrop(src,dst):	
	img = Image.open(src,'r')
	region = (100,200,400,500)

	#crop the image 
	cropImg = img.crop(region)

	#save the image croped	
	cropImg.save(dst)



	
if __name__ == '__main__':
	imageCrop('E:\\sz2\\project\\REDX\\window_source\\MediaLab\\Lab3\\test.jpg','E:\\sz2\\project\\REDX\\window_source\\MediaLab\\Lab3\\test_croped.jpg');
	
	
	
	

#
# one new idea about the image showing approach, think more about it 
#
#box = (100,100,500,500)#设置要拷贝的区域

#将im表示的图片对象拷贝到region中，大小为(400*400)像素。这个region可以用来后续的操作(region其实就是一个Image对象)，box变量是一个四元组(左，上，右，下)。
#region = im.crop(box)

#region = region.transpose(Image.ROTATE_180)#从字面上就可以看出，先把region中的Image反转180度，然后再放回到region中。
#im.paste(region, box)#粘贴box大小的region到原先的图片对象中。