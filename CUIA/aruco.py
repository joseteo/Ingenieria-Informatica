import cv2
import numpy as np
import sys
import os
if os.path.exists('camara.py'):
    import camara
else:
    print("Es necesario realizar la calibración de la cámara")
    exit()

lena = cv2.imread("lena.tif")

DIC = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_5X5_50)
parametros = cv2.aruco.DetectorParameters()

cap = cv2.VideoCapture(0)
if cap.isOpened():
    hframe = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    wframe = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    print("Tamaño del frame de la cámara: ", wframe, "x", hframe)

    matrix, roi = cv2.getOptimalNewCameraMatrix(camara.cameraMatrix, camara.distCoeffs, (wframe,hframe), 1, (wframe,hframe))
    roi_x, roi_y, roi_w, roi_h = roi

    final = False
    while not final:
        ret, framebgr = cap.read()
        if ret:
            # Aquí procesamos el frame
            framerectificado = cv2.undistort(framebgr, camara.cameraMatrix, camara.distCoeffs, None, matrix)
            framerecortado = framerectificado[roi_y : roi_y + roi_h, roi_x : roi_x + roi_w]


            (corners, ids, rejected) = cv2.aruco.detectMarkers(framerecortado, DIC, parameters=parametros)
            if len(corners)>0:
                #print(ids.flatten)
                for i in range(len(corners)):
                    cv2.polylines(framerecortado, [corners[i].astype(int)], True, (0,255,0), 4)
                    centro = corners[i][0][0]
                    for j in range(3):
                        centro = centro + corners[i][0][j+1]
                    centro = centro / 4
                    #cv2.putText(framerecortado, str(ids[i][0]), centro.astype(int), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,0,0), 2)
                    cv2.putText(framerecortado, str(ids[i][0]), corners[i][0][0].astype(int), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,0,0), 2)

                    pts1 = np.float32(corners[i][0])
                    pts2 = np.float32([[0,0],[512,0],[512,512],[0,512]])
                    M = cv2.getPerspectiveTransform(pts2,pts1)
                    dst = cv2.warpPerspective(lena,M,(roi_w,roi_h))

                    cv2.imshow("LENA", dst)

            cv2.imshow("RECORTADO", framerecortado)
            if cv2.waitKey(1) == ord(' '):
                final = True
        else:
            final = True
else:
    print("No se pudo acceder a la cámara.")
