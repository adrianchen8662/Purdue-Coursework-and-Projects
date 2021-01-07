# -*- coding: utf-8 -*-
"""
Created on Thu Oct 17 07:40:39 2019
@author: adela
"""
from PIL import Image
import numpy as np

def smooth(imagename):
    
    #opens image
    image = Image.open(imagename)

    #determines width and height of image
    w, h = image.size

    #creates a new image of the same width and height with empty pixels
    smoothed = Image.new("RGB", (w, h), "white")
    image_map = smoothed.load()
    
    #reads image for all pixels not on the border
    for i in range(1,w-1):
        for j in range(1,h-1):
            #gets values for pixels in a 3x3 area around [i,j]
            pix1 = image.getpixel((i-1,j-1))
            pix2 = image.getpixel((i-1,j)) 
            pix3 = image.getpixel((i-1,j+1)) 
            pix4 = image.getpixel((i,j-1)) 
            pix5 = image.getpixel((i,j)) 
            pix6 = image.getpixel((i,j+1)) 
            pix7 = image.getpixel((i+1,j-1)) 
            pix8 = image.getpixel((i+1,j)) 
            pix9 = image.getpixel((i+1,j+1))
            
            #determines average (devides by 9)
            red = 0
            blue = 0
            green = 0
            for pix in pix1, pix2, pix3, pix4, pix5, pix6, pix7, pix8, pix9:
                red += int(pix[0]/9)
                green += int(pix[1]/9)
                blue += int(pix[2]/9)
           
            image_map[i, j] = (red, green, blue)
            
    smoothed.save(imagename[:-4]+"_smoothed.jpg")
    #imagename[:-4] + "_grayscale.jpg"
           

#a = np.asarray(image)
#    print(a)
"""
from PIL import Image
import numpy as np
import matplotlib.pylab as plt
image = Image.open('Puppy_project_image.jpg')
def smooth(image):
    w, h = image.size
    print(w)
    print(h)
    pix = Image.smooth("RBG", (w, h), "white")
    pixelmap = pix.load()
    kernel = np.ones((3,3),np.float32)/(9)
    
    for i in range(w):
        for j in range(h):
            pixel = image.getpixel((i, j))
            pixel_new = kernel*image(i-1,j-1) + kernel*image(i-1,j) +
            kernel*image(i-1,j+1) + kernel*image(i,j-1) + kernel*image(i,j) +
            kernel*image(i,j+1) + kernel*image(i+1,j-1) + kernel*image(i+1, j) +
            kernel*image(i+1,j+1)
            
            pixelmap[i, j] = pixel_new
            
    return pix
smooth(image)"""
