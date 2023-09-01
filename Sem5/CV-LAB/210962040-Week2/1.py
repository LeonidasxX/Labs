import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./resource/cv-img1.jpg', 0)
hist_original = cv2.calcHist([img],[0],None,[256],[0,256])

# cv2.imshow('image',img)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
equ = cv2.equalizeHist(img)
# cv2.imshow('equalized', equ)
# cv2.waitKey(0)
# cv2.destroyAllWindows()


hist_equalized = cv2.calcHist([equ],[0],None,[256],[0,256])

fig, axs = plt.subplots(2,2,figsize=(12,8))

axs[0,0].imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
axs[0,0].set_title('Original')

axs[1,0].plot(hist_original, color='black')
axs[1,0].set_title('Original Histogram')
axs[1,0].set_xlim([0,256])

axs[0,1].imshow(cv2.cvtColor(equ, cv2.COLOR_BGR2RGB))
axs[0,1].set_title('Equalized')

axs[1,1].plot(hist_equalized, color='black')
axs[1,1].set_title('Equalized Histogram')
axs[1,1].set_xlim([0,256])

plt.tight_layout()
plt.show()





# hist, bins = np.histogram(img.flatten(),256,[0,256])
# cdf = hist.cumsum()
# cdf_normalized = cdf * float(hist.max()) / cdf.max()
# plt.plot(hist_original, color='b')
# plt.title('Image Histogram For Blue Channel GFG')
# plt.show()







# hist,bins = np.histogram(equ.flatten(),256,[0,256])
# cdf = hist.cumsum()
# cdf_normalized = cdf * float(hist.max()) / cdf.max()
# plt.plot(hist_equalized, color='b')
# plt.title('Image Histogram For Blue Channel GFG')
# plt.show()
#
# res = np.hstack((img, equ))
# cv2.imshow('image', res)
# cv2.waitKey(0)
# cv2.destroyAllWindows()


# plt.show()

