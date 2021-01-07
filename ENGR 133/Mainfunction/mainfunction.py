from Grayscale_final import grayscale
from Rotation import rotate90, rotate180, rotate270, mirror
from smoothing import smooth

jpgname = input("Type the name of the jpeg you wish to process = ")

grayscale(jpgname)
print("Grayscale image created successfully")

smooth(jpgname)
print("Smoothing imaged created successfully")

rotationnumber = input("Type how many degrees you wish to rotate(90,180,270), or mirror = ")
if (rotationnumber == "mirror"):
    mirror(jpgname)
    print("Mirror created successfully")
elif (int(rotationnumber) == 90):
    rotate90(jpgname)
    print("Rotation of 90 degrees created successfully")
elif (int(rotationnumber) == 180):
    rotate180(jpgname)
    print("Rotation of 180 degrees created successfully")
elif (int(rotationnumber) == 270):
    rotate270(jpgname)
    print("Rotation of 270 degrees created successfully")
else:
    print("No such angle or name exists, check your spelling")
    
