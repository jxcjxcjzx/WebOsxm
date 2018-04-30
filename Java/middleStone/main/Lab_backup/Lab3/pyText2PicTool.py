# this is py pic generating tool
# for text-pic  transforming 
#coding UTF-8
import pygame
import os
from pygame.locals import *

def simpleText2PicDemo():
# a simple demo
	pygame.init()
	text = u"write a GPS reminder to shut down GPS to save power"
	# set the font and size
	font = pygame.font.SysFont('SimHei',14)
	ftext = font.render(text,True,(0,0,0),(255,255,255))
	# save the pic, the most last thing
	pygame.image.save(ftext,"D:/demo.bmp")

	
		
if __name__ == '__main__':
	simpleText2PicDemo()