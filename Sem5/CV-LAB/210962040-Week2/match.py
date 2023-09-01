import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./resource/cv-img1.jpg')
cv2.imshow('image', img)

image_bw = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

clahe = cv2.createCLAHE(clipLimit=5)
final_img = clahe.apply(image_bw) + 30

_, ordinary_img = cv2.threshold(image_bw, )
