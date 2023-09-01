import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./resource/source.jpg')

cv2.imshow('Original Image', img)


Gaussian = cv2.GaussianBlur(img, (7,7), 0)
cv2.imshow('Gaussian Blurring', Gaussian)
cv2.waitKey(0)

cv2.destroyAllWindows()

kernelSize = [(3,3),(5,5),(7,7),(11,11)]
fig, axs = plt.subplots(1,len(kernelSize))

for count, i in enumerate(kernelSize):
    # Creating the kernel(2d convolution matrix)
    kernel1 = np.ones(i, np.float32)/i[0]**2

    # Applying the filter2D() function
    img = cv2.GaussianBlur(img, i, 0)
    axs[count].imshow(img)
    axs[count].set_title(f"{i[0]}x{i[1]}")

plt.show()