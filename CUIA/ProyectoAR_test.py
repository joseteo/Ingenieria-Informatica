import cv2
import mediapipe as mp
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import matplotlib.pyplot as plt

mp_dibujo = mp.solutions.drawing_utils
mp_manos = mp.solutions.hands

# Inicializar objeto cubo
cube_verts = np.array([
    [1, 1, 1],
    [1, 1, -1],
    [1, -1, -1],
    [1, -1, 1],
    [-1, 1, 1],
    [-1, 1, -1],
    [-1, -1, -1],
    [-1, -1, 1]
])
cube_faces = np.array([
    [0, 1, 2, 3],
    [4, 5, 6, 7],
    [0, 1, 5, 4],
    [1, 2, 6, 5],
    [2, 3, 7, 6],
    [3, 0, 4, 7]
])
cube = Poly3DCollection([cube_verts[cube_faces[i]] for i in range(len(cube_faces))])
cube.set_color('blue')

# Configurar la transmisión en vivo
cap = cv2.VideoCapture(0)

# Configurar la figura de matplotlib
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.add_collection(cube)
plt.ion()
plt.show()

# Declarar las variables
width, height = 640, 480
output_landmarks = []
landmark_id = [mp_manos.HandLandmark.WRIST, 
               mp_manos.HandLandmark.THUMB_TIP, mp_manos.HandLandmark.INDEX_FINGER_TIP, 
               mp_manos.HandLandmark.MIDDLE_FINGER_TIP, mp_manos.HandLandmark.RING_FINGER_TIP, 
               mp_manos.HandLandmark.PINKY_TIP]
proj_matrix = np.array([[1.0, 0, width / 2.0], [0, 1.0, height / 2.0], [0, 0, 1.0]])


# Configurar la transmisión en vivo
cap = cv2.VideoCapture(0)

# Inicializar MediaPipe
with mp_manos.Hands(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as hands:

    # Obtener la matriz de proyección
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            print("No se puede abrir la cámara")
            break

        frame = cv2.flip(frame, 1)
        frame_height, frame_width, _ = frame.shape
        proj_matrix = np.array([
            [2.0 / frame_width, 0, 0, -1.0],
            [0, -2.0 / frame_height, 0, 1.0],
            [0, 0, 0, 0],
            [0, 0, 0, 1.0]
        ],
            dtype=np.float64
        )

        # Detectar las manos en el frame
        results = hands.process(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))

        if results.multi_hand_landmarks:
            # Dibujar las marcas y la caja delimitadora alrededor de las manos
            for hand_landmarks in results.multi_hand_landmarks:
                mp_dibujo.draw_landmarks(
                    frame, hand_landmarks, mp_manos.HAND_CONNECTIONS)

                # Proyectar las marcas de la mano en el espacio 3D
                output_landmarks = []
                for idx, landmark in enumerate(hand_landmarks.landmark):
                    finger_tip_id = [4, 8, 12, 16, 20]
                    if idx in finger_tip_id:
                        x = int(landmark.x * width)
                        y = int(landmark.y * height)
                        z = landmark.z
                        output_landmarks.append([x, y, z])

                # Dibujar el cubo en la posición 3D de cada punta de dedo detectada
                for landmark_3d in output_landmarks:
                    # Convertir la posición 3D de la punta del dedo a 4D
                    landmark_3d_4d = np.array([landmark_3d[0], landmark_3d[1], landmark_3d[2], 1])
                    # Proyectar la posición 3D de la punta del dedo a 2D
                    landmark_2d, _ = cv2.projectPoints(landmark_3d_4d, (0, 0, 0), (0, 0, 0), proj_matrix, None)
                    landmark_2d = tuple(map(int, landmark_2d[0].ravel()))
                    # Dibujar el cubo en la posición 2D de la punta del dedo
                    ax.scatter(landmark_3d[0], landmark_3d[1], landmark_3d[2], s=50, c='red')
                    ax.scatter(landmark_3d[0]+1, landmark_3d[1], landmark_3d[2], s=50, c='red')
                    ax.scatter(landmark_3d[0]-1, landmark_3d[1], landmark_3d[2], s=50, c='red')
                    ax.scatter(landmark_3d[0], landmark_3d[1]+1, landmark_3d[2], s=50, c='red')
                    ax.scatter(landmark_3d[0], landmark_3d[1]-1, landmark_3d[2], s=50, c='red')
                    ax.scatter(landmark_3d[0], landmark_3d[1], landmark_3d[2]+1, s=50, c='red')
                    ax.scatter(landmark_3d[0], landmark_3d[1], landmark_3d[2]-1, s=50, c='red')
                    cube.set_verts([cube_verts[cube_faces[i]] + landmark_3d for i in range(len(cube_faces))])
                    ax.add_collection(cube)

        cv2.imshow('Detector Manos', frame)

        # Salir del programa si se presiona ' '
        if cv2.waitKey(1) == ord(" "):
            break

# Limpiar la memoria
cap.release()
cv2.destroyAllWindows()