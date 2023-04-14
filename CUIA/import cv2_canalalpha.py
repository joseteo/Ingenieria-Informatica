import cv2
import numpy as np

img = cv2.imread('lena.tif', cv2.IMREAD_UNCHANGED)
b, g, r = cv2.split(img)

# Crea una imagen vacía con las mismas dimensiones que la imagen original
red_img = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)
green_img = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)
blue_img = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)

# Copia los canales de colores RGB en los canales correspondientes de las nuevas imágenes
red_img[:,:,2] = r
green_img[:,:,1] = g
blue_img[:,:,0] = b

# Muestra las imágenes resultantes
cv2.imshow("Red channel", red_img)
cv2.imshow("Green channel", green_img)
cv2.imshow("Blue channel", blue_img)
cv2.waitKey(0)