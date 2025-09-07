import cv2
import mediapipe as mp

# Initialize MediaPipe Hands and Drawing utilities
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils

# Initialize camera
camera1 = cv2.VideoCapture(0)

# Initialize Hands model once before the loop
hands = mp_hands.Hands(max_num_hands = 2, min_detection_confidence=0.7, min_tracking_confidence=0.7)

while True:
    ret1, frame1 = camera1.read()

    # If the frame is not read correctly, break the loop
    if not ret1:
        print("Failed to grab frame")
        break

    # Convert the frame to RGB (MediaPipe uses RGB)
    frame1_rgb = cv2.cvtColor(frame1, cv2.COLOR_BGR2RGB)

    # Process the frame with the Hand tracking model
    results = hands.process(frame1_rgb)

    # Convert back to BGR for displaying
    frame1 = cv2.cvtColor(frame1_rgb, cv2.COLOR_RGB2BGR)

    # If hand landmarks are detected, draw them
    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            mp_drawing.draw_landmarks(frame1, hand_landmarks, connections=mp_hands.HAND_CONNECTIONS)

    # Show the resulting frame
    cv2.imshow('Hand Tracking', frame1)

    # Exit the loop when 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close any OpenCV windows
camera1.release()
cv2.destroyAllWindows()
