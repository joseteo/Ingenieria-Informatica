import cv2
import numpy as np
rgb = np.random.randint(255, size=(1024,1024,3), dtype=np.uint8)
cv2.imshow('TEST', rgb)
cv2.resizeWindow('TEST', 1024, 1024)
cv2.waitKey()
cv2.destroyWindow('TEST')