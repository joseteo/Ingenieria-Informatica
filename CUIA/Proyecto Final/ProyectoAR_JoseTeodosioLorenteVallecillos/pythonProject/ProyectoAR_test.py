import cv2
#from cv2 import error
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import mediapipe as mp
import numpy as np
import os
import SeguimientoManos as sm
import autopy
import IPython.display as ipd
import re
import pyttsx3
import speech_recognition as sr
import dibujar_raton as d

dibu = d.dibujar
rec = sr.Recognizer()
mic = sr.Microphone()
engine = pyttsx3.init()
voices = engine.getProperty('voices')
anchocam, altocam = 640, 480
cuadro = 50
anchopantalla, altopantalla = autopy.screen.size()
sua = 5
pubix, pubiy = 0,0
cubix, cubiy = 0,0
mp_dibujo = mp.solutions.drawing_utils
mp_manos = mp.solutions.hands
mp_drawing_styles = mp.solutions.drawing_utils

dataPath = 'C:/Users/joset/Documents/Ing. Informatica/Segundo Cuatri/CUIA/Reconocimiento Facial/Data'
imagePaths = os.listdir(dataPath)
print('Lista de personas: ', imagePaths)

face_recognizer = cv2.face.EigenFaceRecognizer_create()

face_recognizer.read('modeloReconocimientoFacial.xml')


# Inicializar objeto cubo
cube_verts = np.array([    [1, 1, 1],
    [1, 1, -1],
    [1, -1, -1],
    [1, -1, 1],
    [-1, 1, 1],
    [-1, 1, -1],
    [-1, -1, -1],
    [-1, -1, 1]]
    , dtype=np.float64
)
cube_faces = np.array([    [0, 1, 2, 3],
    [4, 5, 6, 7],
    [0, 1, 5, 4],
    [1, 2, 6, 5],
    [2, 3, 7, 6],
    [3, 0, 4, 7]]
    , dtype=np.float64
)

# Agregar la coordenada z a cada vértice del cubo
cube_verts = np.hstack((cube_verts, np.ones((8, 1))))

proj_matrix = np.array([[1.0, 0, 0, 0], [0, 1.0, 0, 0], [0, 0, 1.0, 0]], dtype=np.float64)

# Configurar la transmisión en vivo
cap = cv2.VideoCapture(0)

detector = sm.detectormanos(maxManos=1)

faceClassif = cv2.CascadeClassifier(cv2.data.haarcascades+'haarcascade_frontalface_default.xml')

# Crear figura y axis 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

index = [4, 8, 12, 16, 20]

modo_r_d = False #si es falso esta en modo raton, si es true esta en modo dibujar
circulo = False #si es true esta en modo dibujo circulo, y si es false no lo esta
rectangulo = False #si es true esta en modo dibujo rectanfgulo, y si es false no lo esta

with mp_manos.Hands(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as hands:

    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            print("No se puede abrir la cámara")
            break

        frame_height, frame_width, _ = frame.shape

        gray = cv2.cvtColor(frame, cv2.COLOR_BGRA2GRAY)
        auxFrame = gray.copy()

        faces = faceClassif.detectMultiScale(gray, 1.3, 5)

        for (x,y,w,h) in faces:
            rostro = auxFrame[y:y+h, x:x+w]
            rostro = cv2.resize(rostro, (150,150), interpolation= cv2.INTER_CUBIC)
            result = face_recognizer.predict(rostro)

            cv2.putText(frame, '{}'.format(result), (x,y-5), 1, 1.3, (255,255,0), 1, cv2.LINE_AA)

            if result[1] < 5700:
                try:
                    with mic as source:
                        rec.adjust_for_ambient_noise(source, duration=0.5)
                        audio = rec.listen(source)

                        texto = rec.recognize_google(audio, language='es-ES')

                        if re.search(r"Alfred", texto, re.IGNORECASE):
                            print(f'\n Hola {imagePaths[result[0]]}')

                            engine.setProperty('rate', 160)
                            engine.setProperty('voice',
                                               'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_ES-ES_HELENA_11.0')
                            engine.say(f'Hola {imagePaths[result[0]]}')

                            if re.search(r"Ratón|ratón|Raton|raton", texto, re.IGNORECASE):
                                print('Seleccionada Mano Raton Virtual')
                                modo_r_d = False
                            elif re.search(r"Dibujar|circulo", texto, re.IGNORECASE) \
                                    and (result[0] == 0 or result[0] == 2):
                                modo_r_d = True
                                circulo = True
                                rectangulo = False
                                print('Ha seleccionado dibujar la forma circulo')
                            elif re.search(r"Dibujar|rectangle", texto, re.IGNORECASE) \
                                    and (result[0] == 0 or result[0] == 2):
                                modo_r_d = True
                                rectangulo = True
                                circulo = False
                                print('Ha seleccionado dibujar la forma rectagnulo')

                except sr.RequestError:
                    print("API no disponible")
                except sr.UnknownValueError:
                    print("")

                cv2.putText(frame, '{}'.format(imagePaths[result[0]]), (x, y-25), 2, 1.1, (0, 255, 0), 1, cv2.LINE_AA)
                cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

                if not modo_r_d:
                    # Detectar las manos en el frame
                    frame = detector.encontrarmanos(frame)
                    lista, bbox = detector.encontrarposicion(frame)

                    if len(lista) != 0:
                        x1, y1 = lista[8][1:]
                        x2, y2 = lista[12][1:]

                        dedos = detector.dedosarriba()

                        cv2.rectangle(frame, (cuadro, cuadro), (anchocam - cuadro, altocam - cuadro),
                                      (0, 0, 0), 2)

                        if dedos[1] == 1 and dedos[2] == 0:
                            x3 = np.interp(x1, (cuadro, anchocam - cuadro), (0, anchopantalla))
                            y3 = np.interp(y1, (cuadro, altocam - cuadro), (0, altopantalla))

                            cubix = pubix + (x3 - pubix) / sua
                            cubiy = pubiy + (y3 - pubiy) / sua

                            autopy.mouse.move(anchopantalla - cubix, cubiy)
                            cv2.circle(frame, (x1, y1), 10, (0, 0, 0), cv2.FILLED)
                            pubix, pubiy = cubix, cubiy

                        if dedos[1] == 1 and dedos[2] == 1:
                            longitud, frame, linea = detector.distancia(8, 12, frame)
                            if longitud < 30:
                                cv2.circle(frame, (linea[4], linea[5]), 10, (0, 255, 0), cv2.FILLED)

                                autopy.mouse.click()
                elif modo_r_d and (result[0] == 0 or result[0] == 2):
                    if rectangulo:
                        cv2.setMouseCallback('Proyecto', d.dibujar.dibujar_rectangulo)
                        rectangulo = False
                        modo_r_d = False
                    elif circulo:
                        cv2.setMouseCallback('Proyecto', d.dibujar.dibujar_circulo)
                        circulo = False
                        modo_r_d = False
            else:
                cv2.putText(frame, 'Desconocido', (x, y-20), 2, 0.8, (0, 0, 255), 1, cv2.LINE_AA)
                cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2)


        

        # Mostrar la transmisión en vivo
        cv2.imshow("Proyecto", frame)

        # Salir del loop cuando se presiona " "
        if cv2.waitKey(1) & 0xFF == 27:
            break

# Limpiar la memoria
cap.release()
cv2.destroyAllWindows()