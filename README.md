# 🤖 Mobile Robot with 3D Printed Manipulator Arm (Bluetooth Controlled)

An Arduino-powered mobile robot with a 3D-printed, servo-controlled manipulator arm for wireless pick-and-place operations. Controlled via a custom Android app using the HC-05 Bluetooth module, this prototype demonstrates mobile manipulation capabilities typically found in high-end industrial robots—made affordable and customizable.

---

## 🔧 System Architecture

- **Dual Arduino Boards**: Independent control for locomotion and manipulation.
- **Drive System**: 4WD Johnson motors + L298N H-Bridge Motor Driver.
- **Manipulator Arm**: 4-DOF 3D printed robotic arm actuated via PWM servo motors.
- **Wireless Control**: HC-05 Bluetooth module interfacing with a mobile application.
- **Power Regulation**: 24V to 12V step-down voltage regulator powering motor drivers and servos.
- **App Interface**: Bluetooth-connected Android app for directional and joint control.

---

## 🧠 Core Features

- ✅ Autonomous & Remote pick-and-place functionality.
- ✅ Modular architecture—arm and chassis controlled via separate Arduinos.
- ✅ Fully open-source 3D printed manipulator (STL files included).
- ✅ Reprogrammable movement sequences via app (SAVE / RUN / RESET logic).
- ✅ Robust embedded logic with feedback loop-style servo control.
- ✅ Excellent for educational, prototyping, and remote inspection use cases.

---

## 📷 Media Preview

| Architecture | 3D Arm Design | Circuit |
|--------------|---------------|---------|
| ![system](docs/images/system_architecture.png) | ![arm](docs/images/robot_arm_3dprint.jpg) | ![circuit](docs/images/circuit_diagram.jpg) |

---

## 🔌 Hardware Bill of Materials

| Component | Quantity | Purpose |
|----------|----------|---------|
| Arduino Mega + Uno | 2 | Motion + Manipulator control |
| HC-05 Bluetooth Module | 1 | Wireless communication |
| L298N Motor Driver | 1 | DC motor control |
| Johnson 12V Geared Motors | 4 | Chassis drive |
| Servo Motors (SG90/MG996R) | 4+ | Joint control |
| 3D Printed Parts | - | Arm and Chassis |
| Voltage Regulator (24V → 12V) | 1 | Stable power distribution |

---

## 📂 Repository Contents

- `code/`: Arduino sketches for chassis and manipulator
- `hardware/`: Circuit diagrams and schematics (Fritzing & PNG)
- `3d_models/`: STL files for printing the arm and chassis
- `mobile_app/`: APK for Android Bluetooth controller
- `docs/`: Project report, images, and supporting diagrams
- `test_videos/`: Demo showcasing robot capabilities

---

## 📱 Android App Control

- **Buttons 1–5**:
  - `1`: Forward
  - `2`: Backward
  - `3`: Turn Left
  - `4`: Turn Right
  - `5`: Stop
- **Servo Controls**:
  - `SAVE`: Stores servo positions
  - `RUN`: Executes stored sequence
  - `RESET`: Clears all memory

---

## 🔍 Experimental Insights

- **Smooth Mobility**: Verified on tile, wood, and carpeted surfaces.
- **Precise Arm Motion**: Smooth trajectory and pose memory using incremental loop logic.
- **Low-latency Bluetooth Control**: <100ms command delay at 5m distance.

---

## 📈 Results

- Complete wireless pick-and-place control demonstrated.
- All user inputs reflected in real-time with no signal drop.
- Rapid reprogramming of arm movement through mobile interface.
- Easily replicable and scalable design.

---

## 📚 Documentation

- [📄 Mini Project Report (PDF)](./docs/Mini_Project_Report.pdf)
- Circuit design created via [Circuito.io](https://www.circuito.io)
- 3D Models made using Fusion360 & printed with PLA

---

## 🧠 Future Enhancements

- Integrate camera for object recognition
- Add feedback sensors for closed-loop control
- Replace Bluetooth with WiFi (ESP32) for wider control range
- ROS2 implementation for autonomous path planning

---

## Author
- **Siddharth Huddar**
- B.Tech Mechatronics Engineering 
