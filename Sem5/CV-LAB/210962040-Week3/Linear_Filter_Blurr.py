# importing the modules needed
import cv2
import matplotlib.pyplot as plt
import numpy as np

# Reading the image
image = cv2.imread('./resource/source.jpg')

kernelSize = [(3,3),(5,5),(7,7),(11,11)]
fig, axs = plt.subplot(1,len(kernelSize))

for count, i in enumerate(kernelSize):
    # Creating the kernel(2d convolution matrix)
    kernel1 = np.ones(i, np.float32)/i[0]**2

    # Applying the filter2D() function
    img = cv2.filter2D(src=image, ddepth=-1, kernel=kernel1)
    axs[count].imshow(img)
    axs[count].set_title(f"{i[0]}x{i[1]}")

plt.show()
