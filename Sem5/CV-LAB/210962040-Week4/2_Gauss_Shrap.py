import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./resource/sharp.jpg')

cv2.imshow('Original Image', img)


Gaussian = cv2.GaussianBlur(img, (7,7), 0)
cv2.imshow('Gaussian Blurring', Gaussian)

sub = cv2.subtract(img,Gaussian)
cv2.imshow('UnSharped Image, img-Gauss', sub)

add = cv2.add(img,sub)
cv2.imshow('Sharped Image, img+sub', add)

cv2.waitKey(0)

cv2.destroyAllWindows()