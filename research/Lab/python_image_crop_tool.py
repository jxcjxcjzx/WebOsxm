import Image

img = Image.open(r'E:\photo\20120402\abc.jpg')
region = (100,200,400,500)

#裁切图片
cropImg = img.crop(region)

#保存裁切后的图片
cropImg.save(r'E:\photo\crop.jpg')