import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./resource/edge_detect.jpg')
cv2.imshow('Original', img)

img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img_gray_n = np.array(img_gray, float)
img_blur = cv2.GaussianBlur(img_gray, (3, 3), 0)
img_blur_n = np.array(img_gray, float)
sobelx = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=1, dy=0, ksize=5)  # Sobel Edge Detection on the X axis
sobely = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=0, dy=1, ksize=5)  # Sobel Edge Detection on the Y axis
sobelxy = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=1, dy=1, ksize=5)  # Combined X and Y Sobel Edge Detection
laplacian = cv2.Laplacian(img_blur,cv2.CV_64F)

grad = (sobelx**2 + sobely**2)**0.5
grad = ((grad - grad.min())/ (grad.max() - grad.min())) *255
cv2.imshow("grad", grad)

final = img_blur_n + grad
cv2.imshow("Final", final)

phase_angle = np.arctan2(sobely, sobelx)

phase_angle_deg = (phase_angle + np.pi) * (180.0 / np.pi)
cv2.imshow('Phase ang', phase_angle_deg.astype(np.uint8))
cv2.waitKey(0)
cv2.destroyAllWindows()
fig,ax = plt.subplots(figsize=(12,8), nrows=1, ncols=2)
grad = np.hypot(sobelx, sobely)
grad = ((grad - grad.min())/ (grad.max() - grad.min())) *255
final = grad + img_gray_n

ax[0].imshow(grad, cmap='gist_gray')
ax[1].imshow(final, cmap='gist_gray')
ax[0].set_title('Gradient')
ax[1].set_title('Final')
plt.show()


