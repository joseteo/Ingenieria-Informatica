import cv2
import numpy as np
lena = cv2.imread('lena.tif')
cv2.imshow('TEST', lena)
cv2.resizeWindow('TEST', 1024, 1024)
cv2.waitKey()
cv2.destroyWindow('TEST')