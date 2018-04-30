import Image, ImageChops
 
def autoCrop(image,backgroundColor=None):
    '''Intelligent automatic image cropping.
       This functions removes the usless "white" space around an image.
        
       If the image has an alpha (tranparency) channel, it will be used
       to choose what to crop.
        
       Otherwise, this function will try to find the most popular color
       on the edges of the image and consider this color "whitespace".
       (You can override this color with the backgroundColor parameter) 
 
       Input:
            image (a PIL Image object): The image to crop.
            backgroundColor (3 integers tuple): eg. (0,0,255)
                 The color to consider "background to crop".
                 If the image is transparent, this parameters will be ignored.
                 If the image is not transparent and this parameter is not
                 provided, it will be automatically calculated.
 
       Output:
            a PIL Image object : The cropped image.
    '''
     
    def mostPopularEdgeColor(image):
        ''' Compute who's the most popular color on the edges of an image.
            (left,right,top,bottom)
             
            Input:
                image: a PIL Image object
             
            Ouput:
                The most popular color (A tuple of integers (R,G,B))
        '''
        im = image
        if im.mode != 'RGB':
            im = image.convert("RGB")
         
        # Get pixels from the edges of the image:
        width,height = im.size
        left   = im.crop((0,1,1,height-1))
        right  = im.crop((width-1,1,width,height-1))
        top    = im.crop((0,0,width,1))
        bottom = im.crop((0,height-1,width,height))
        pixels = left.tostring() + right.tostring() + top.tostring() + bottom.tostring()
 
        # Compute who's the most popular RGB triplet
        counts = {}
        for i in range(0,len(pixels),3):
            RGB = pixels[i]+pixels[i+1]+pixels[i+2]
            if RGB in counts:
                counts[RGB] += 1
            else:
                counts[RGB] = 1   
         
        # Get the colour which is the most popular:       
        mostPopularColor = sorted([(count,rgba) for (rgba,count) in counts.items()],reverse=True)[0][1]
        return ord(mostPopularColor[0]),ord(mostPopularColor[1]),ord(mostPopularColor[2])
     
    bbox = None
     
    # If the image has an alpha (tranparency) layer, we use it to crop the image.
    # Otherwise, we look at the pixels around the image (top, left, bottom and right)
    # and use the most used color as the color to crop.
     
    # --- For transparent images -----------------------------------------------
    if 'A' in image.getbands(): # If the image has a transparency layer, use it.
        # This works for all modes which have transparency layer
        bbox = image.split()[list(image.getbands()).index('A')].getbbox()
    # --- For non-transparent images -------------------------------------------
    elif image.mode=='RGB':
        if not backgroundColor:
            backgroundColor = mostPopularEdgeColor(image)
        # Crop a non-transparent image.
        # .getbbox() always crops the black color.
        # So we need to substract the "background" color from our image.
        bg = Image.new("RGB", image.size, backgroundColor)
        diff = ImageChops.difference(image, bg)  # Substract background color from image
        bbox = diff.getbbox()  # Try to find the real bounding box of the image.
    else:
        raise NotImplementedError, "Sorry, this function is not implemented yet for images in mode '%s'." % image.mode
         
    if bbox:
        image = image.crop(bbox)
         
    return image
 
 
 
#范例：裁剪透明图片:
im = Image.open('myTransparentImage.png')
cropped = autoCrop(im)
cropped.show()
 
#范例：裁剪非透明图片
im = Image.open('myImage.png')
cropped = autoCrop(im)
cropped.show()
