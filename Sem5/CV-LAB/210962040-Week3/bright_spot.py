import cv2

img = cv2.imread("./resource/source.jpg")
original = img.copy()
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

(minVal, maxVal, minLoc, maxLoc) = cv2.minMaxLoc(gray)
cv2.circle(img, maxLoc, 5, (255, 0, 0), 2)

cv2.imshow("Naive", img)

gray = cv2.GaussianBlur(gray, (25, 25), 0)
(minVal, maxVal, minLoc, maxLoc) = cv2.minMaxLoc(gray)
image = original.copy()
cv2.circle(image, maxLoc, 25, (255, 0, 0), 2)
cv2.imshow("Robust", image)
cv2.waitKey(0)