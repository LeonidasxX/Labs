import cv2
import numpy as np

img = cv2.imread('./resource/edge_detect.jpg')
cv2.imshow('Original', img)

img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img_gray_n = np.array(img_gray, float)
img_blur = cv2.GaussianBlur(img_gray, (3, 3), 0)

sobelx = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=1, dy=0, ksize=5)  # Sobel Edge Detection on the X axis
sobely = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=0, dy=1, ksize=5)  # Sobel Edge Detection on the Y axis
sobelxy = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=1, dy=1, ksize=5)  # Combined X and Y Sobel Edge Detection
laplacian = cv2.Laplacian(img_blur,cv2.CV_64F)


sharp_sobelx = img_gray_n + (img_gray_n - sobelx)
cv2.imshow("Sharp_SobelX", sharp_sobelx)
sharp_sobely = img_gray_n + (img_gray_n - sobely)
cv2.imshow("Sharp_SobelY", sharp_sobely)
sharp_sobelxy = img_gray_n + (img_gray_n - sobelxy)
cv2.imshow("Sharp_SobelXY", sharp_sobelxy)

sharp_laplacian = img_gray_n + (img_gray_n - laplacian)
cv2.imshow("Sharp_Laplacian", sharp_laplacian)

cv2.waitKey(0)
cv2.destroyAllWindows()