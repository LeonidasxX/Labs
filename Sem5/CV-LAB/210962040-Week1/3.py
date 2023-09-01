import cv2

image = cv2.imread('C:/Users/OSLAB/PycharmProjects/pythonProject/cvlab/cv-img1.jpg',cv2.IMREAD_UNCHANGED)
b,g,r = (image[300,300])
print(b)
print(g)
print(r)