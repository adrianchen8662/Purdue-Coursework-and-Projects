  
#!/usr/bin/env python3

'''
===============================================================================
ENGR 133 Program Description 
	
Assignment Information
	Assignment:     Python Project
	Author:         Shane Hardin, hardin38@purdue.edu
	Team ID:        001-23
	
===============================================================================
'''
import numpy as np
from PIL import Image
def rotate90(imagename):#creates an empty array of vice versa size and sets the x locations to y locations and vice versa
    image = Image.open(imagename)
    imageMatrix = np.array(image)
    outputMatrix = np.empty((len(imageMatrix[0]),len(imageMatrix), 3))
    
    for x in range(len(outputMatrix)):
        for y in range(len(outputMatrix[0])):
            outputMatrix[x][y] = imageMatrix[y][x]
    
    image2 = Image.fromarray(outputMatrix.astype('uint8'), 'RGB')
    image2.save(imagename[:-4] + "_rotate90.jpg")
    
def rotate180(imagename): #creates empty array of vice versa size, assigns new location of each pixel to length - (current location) - 1 
    image = Image.open(imagename)
    imageMatrix = np.array(image)
    outputMatrix = np.empty((len(imageMatrix),len(imageMatrix[0]), 3))
    
    for x in range(len(outputMatrix)):
        for y in range(len(outputMatrix[0])):
            outputMatrix[x][y] = imageMatrix[len(imageMatrix) - x - 1][len(imageMatrix[0]) - y - 1]
    
    image2 = Image.fromarray(outputMatrix.astype('uint8'), 'RGB')
    image2.save(imagename[:-4] + "_rotate180.jpg")
    
def rotate270(imagename):#calls both rotate180 and rotate90 to create an image rotated270 degrees
    image = Image.open(imagename)
    imageMatrix = np.array(image)
    outputMatrix = np.empty((len(imageMatrix),len(imageMatrix[0]), 3))
    
    for x in range(len(outputMatrix)):
        for y in range(len(outputMatrix[0])):
            outputMatrix[x][y] = imageMatrix[len(imageMatrix) - x - 1][len(imageMatrix[0]) - y - 1]
    
    outputMatrix2 = np.empty((len(outputMatrix[0]),len(outputMatrix), 3))
    
    for x in range(len(outputMatrix2)):
        for y in range(len(outputMatrix2[0])):
            outputMatrix2[x][y] = outputMatrix[y][x]
    
    image2 = Image.fromarray(outputMatrix2.astype('uint8'), 'RGB')
    image2.save(imagename[:-4] + "_rotate270.jpg")
    
def mirror(imagename):#flip image in y direction by creating empty array of same size and moving pixels to length - (current location) - 1 
    image = Image.open(imagename)
    imageMatrix = np.array(image)
    outputMatrix = np.empty((len(imageMatrix),len(imageMatrix[0]), 3))
    
    for x in range(len(outputMatrix)):
        for y in range(len(outputMatrix[0])):
            outputMatrix[x][y] = imageMatrix[len(imageMatrix) - x - 1][y]
    
    image2 = Image.fromarray(outputMatrix.astype('uint8'), 'RGB')
    image2.save(imagename[:-4] + "_mirror.jpg")


   
'''
===============================================================================
ACADEMIC INTEGRITY STATEMENT
    I have not used source code obtained from any other unauthorized
    source, either modified or unmodified. Neither have I provided
    access to my code to another. The project I am submitting
    is my own original work.
=============
