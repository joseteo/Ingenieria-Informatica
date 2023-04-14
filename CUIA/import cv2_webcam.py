import cv2
import numpy as np

cap = cv2.VideoCapture(0)
overlay = cv2.imread('opencv.png', cv2.IMREAD_UNCHANGED)
ret, frame = cap.read()
height, width = frame.shape[:2]

if overlay.shape[2] == 4: # Si la imagen tiene 4 canales
    overlay = cv2.cvtColor(overlay, cv2.COLOR_RGBA2RGB)

overlay_pos = (width - 100, height - 100) # Posición de la esquina inferior derecha de la imagen superpuesta
overlay_size = (100, 100) # Tamaño de la imagen superpuesta
window_size = (640, 480) # Tamaño de la ventana del video

if not cap.isOpened():
    print("No se puede abrir la cámara")
    exit()

while True:
    ret, frame = cap.read()
    if not ret:
        break
    
    # Redimensionar la imagen superpuesta
    overlay_resized = cv2.resize(overlay, overlay_size)
    
    # Superponer la imagen en la esquina inferior derecha de la imagen actual
    frame[overlay_pos[1]:overlay_pos[1]+overlay_size[1], overlay_pos[0]:overlay_pos[0]+overlay_size[0]] = overlay_resized
    
    # Mostrar el video en una ventana
    cv2.imshow('Video', frame)
    if cv2.waitKey(1) == ord(" "):
        break

cap.release()
cv2.destroyWindow('Video')