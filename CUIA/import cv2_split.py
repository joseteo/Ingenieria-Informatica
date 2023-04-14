import cv2
import numpy as np
lena = cv2.imread('lena.tif')
b, g, r = cv2.split(lena)
lena_grb = cv2.merge((r, g, b))
lena_hsv = [cv2.cvtColor(lena_grb, cv2.COLOR_BGR2HSV), cv2.cvtColor(lena_grb, cv2.COLOR_RGB2HSV), cv2.cvtColor(lena_grb, cv2.COLOR_RGB2HSV)]
cv2.imshow('ROJO', lena_hsv[0])
cv2.imshow('VERDE', lena_hsv[1])
cv2.imshow('AZUL', lena_hsv[2])
cv2.waitKey()
cv2.destroyAllWindows()