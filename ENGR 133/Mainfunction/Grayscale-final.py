#!/usr/bin/env python3

'''
===============================================================================
ENGR 133 Program Description 
	replace this text with your program description as a comment
Assignment Information
	Assignment:     e.g. Py1_ACT Task 1
	Author:         Adrian Chen, chen3124@purdue.edu
	Team ID:        001-23 (e.g. 001-14 for section 1 team 14)
	
Contributor:    Name, login@purdue [repeat for each]
	My contributor(s) helped me:	
	[ ] understand the assignment expectations without
		telling me how they will approach it.
	[ ] understand different ways to think about a solution
		without helping me plan my solution.
	[ ] think through the meaning of a specific error or
		bug present in my code without looking at my code.
	Note that if you helped somebody else with their code, you
	have to list that person as a contributor here as well.
===============================================================================
'''
from PIL import Image
#defines a function that takes an image and converts the image to grayscale,
#then returns values for the pixels
def grayscale(imagename):
    image = Image.open(imagename)
    width, height = image.size
    
    #creates a blank canvas to assign RGB values to
    pix = Image.new("RGB", (width, height), "white")
    pixelmap = pix.load()
    
    #for loops to cover the width and height of the image
    for i in range(width):
        for j in range(height):
            
            #gets RGB values from the original image and splits into red, green and blue values
            pixel = image.getpixel((i, j))
            
            red = pixel[0]
            green = pixel[1]
            blue = pixel[2]
            
            #grayscale conversion from RGB values, accounted with gamma correction
            grayscale = int((red * 0.299) + (green * 0.587) + (blue * 0.114))
            
            #maps the grayscale data to pixelmap
            pixelmap[i, j] = (grayscale, grayscale, grayscale)
            
    #saves a grayscale image     
    pix.save(imagename[:-4] + "_grayscale.jpg")

'''
===============================================================================
ACADEMIC INTEGRITY STATEMENT
    I have not used source code obtained from any other unauthorized
    source, either modified or unmodified. Neither have I provided
    access to my code to another. The project I am submitting
    is my own original work.
===============================================================================
'''
