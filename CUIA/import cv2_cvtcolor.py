import cv2
import numpy as np
lena = cv2.imread('lena.tif')
lena_hsv = cv2.cvtColor(lena, cv2.COLOR_BGR2HSV)
h, s, v = cv2.split(lena_hsv)

cv2.imshow('TONO', h)
cv2.imshow('SATURACION', s)
cv2.imshow('VALOR', v)
cv2.waitKey()
cv2.destroyAllWindows()