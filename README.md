# MakeUofT2025 - justGroov3d

A 3D music rhythm game that utilizes wearable techonology. Link to [devpost](https://devpost.com/software/rhythmgroov3d).

This project combines **computer vision (Python + OpenCV + MediaPipe)** and **embedded sensing (Arduino + Flex Sensors + ADXL362 accelerometer)** to capture and analyze hand gestures and movement during gameplay.

## Features

- **Python Hand Tracking (OpenCV + MediaPipe)**

  - Tracks up to **two hands** in real-time from the webcam.
  - Detects and draws hand landmarks & connections.

- **Arduino Sensor Integration**
  - Reads **flex sensor** values to capture finger bending.
  - Interfaces with an **ADXL362 accelerometer** over SPI.
  - Outputs calibrated accelerometer and flex sensor data over Serial.
  - Configurable calibration offsets for sensor accuracy.

## Requirements

Python (Hand Tracking)

- Python 3.8+
- OpenCV
- MediaPipe

Install dependencies:

```bash
pip install opencv-python mediapipe
```

Arduino (Sensor Integration)

- Arduino IDE
- 2x Flex sensors
- ADXL362 accelerometer (SPI)

## License

This template and the code in it is licensed under the [MIT License](https://github.com/marcizhu/readme-chess/LICENSE).
