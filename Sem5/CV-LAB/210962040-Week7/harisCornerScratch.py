import cv2
import numpy as np

def harris(img, threshold = 0.6):
    i = img.copy()
    i_gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    dx = cv2.Sobel(i_gray, 0, ksize=3, dx=1, dy=0)
    dy = cv2.Sobel(i_gray, 0, ksize=3, dx=0, dy=1)

    dx2 = np.square(dx)
    dy2 = np.square(dy)
    dxdy = dx*dy

    g_dx2 = cv2.GaussianBlur(dx2, ksize=(3,3), sigmaX=1)
    g_dy2 = cv2.GaussianBlur(dy2, ksize=(3, 3), sigmaX=1)
    g_dxdy = cv2.GaussianBlur(dxdy, ksize=(3, 3), sigmaX=1)

    harris = g_dx2*g_dy2 - np.square(g_dxdy) - 0.12*np.square(g_dx2+g_dy2)
    cv2.normalize(harris, harris, 0, 1, cv2.NORM_MINMAX)

    loc = np.where(harris >= threshold)
    for pt in zip(*loc[::-1]):
        cv2.circle(i, pt, 3, (0,0,255), -1)

    return i, g_dx2, g_dy2, dx, dy, loc


img = cv2.imread('./resource/chess.png')
corners,g_dx2,g_dy2,dx,dy,loc = harris(img,0.85)
cv2.imshow('Corners',corners)
cv2.waitKey(0)
cv2.destroyAllWindows()
