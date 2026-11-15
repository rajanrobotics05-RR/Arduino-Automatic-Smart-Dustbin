# 🗑️ Automatic Smart Dustbin using Arduino

**Developed by Rajan Robotics**  
*Vision to Reality*

## 📌 Project Overview

The Automatic Smart Dustbin is an Arduino-based automation project that opens its lid automatically when a person brings their hand near the ultrasonic sensor.

The HC-SR04 ultrasonic sensor detects the presence of an object or hand. Arduino processes the distance measurement and controls an SG90 servo motor to open and close the dustbin lid.

This project promotes touch-free waste disposal and demonstrates the practical application of embedded systems, sensors and robotics.

## ✨ Features

- Automatic touch-free lid opening.
- Ultrasonic distance measurement.
- Servo motor-based lid control.
- Automatic lid closing after a preset delay.
- Simple and beginner-friendly Arduino implementation.
- Low-cost educational robotics project.

## 🔧 Components Required

| S.No. | Component | Quantity |
|---|---|---:|
| 1 | Arduino Uno | 1 |
| 2 | HC-SR04 Ultrasonic Sensor | 1 |
| 3 | SG90 Servo Motor | 1 |
| 4 | Dustbin with movable lid | 1 |
| 5 | Jumper wires | As required |
| 6 | Breadboard | 1 (optional) |
| 7 | External regulated 5V supply | 1 (if required by servo) |

## 🔌 Pin Connections

### HC-SR04 Ultrasonic Sensor

| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

### SG90 Servo Motor

| Servo Wire | Arduino Connection |
|---|---|
| Brown | GND |
| Red | 5V supply |
| Orange | D6 |

**Important:** If using an external 5V supply for the servo, connect its GND to Arduino GND. Avoid powering a servo that draws significant current directly from the Arduino 5V pin.

## ⚙️ Working Principle

1. The ultrasonic sensor continuously measures the distance in front of the dustbin.
2. When a hand is detected within the predefined distance, Arduino activates the servo motor.
3. The servo rotates to open the lid.
4. After the hand moves away and the waiting time expires, the servo returns to its original position.
5. The lid closes automatically.

## 🧠 Applications

- Touch-free household dustbins.
- Smart waste management demonstrations.
- School and college robotics projects.
- Embedded systems learning.
- STEM and automation workshops.

## 🛠️ Software Requirements

- Arduino IDE
- Servo library (included with Arduino IDE)

## 📁 Repository Structure

```text
Arduino-Automatic-Smart-Dustbin/
│
├── Code/
│   └── Smart_Dustbin.ino
│
├── Circuit/
│   └── Smart_Dustbin_Circuit.png
│
├── Images/
│   └── Smart_Dustbin_Prototype.jpg
│
├── Videos/
│   └── demo_video_link.txt
│
├── README.md
└── LICENSE
```

## 🚀 Future Improvements

- Add an LCD to display dustbin status.
- Add a bin-full detection sensor.
- Add IoT-based waste monitoring.
- Add battery-powered operation.

## 👨‍🏫 Developed By

**Rajan Robotics**  
*Vision to Reality*

Practical Robotics | Embedded Systems | IoT | Electronics Education

## 🔌 Circuit Diagram

![Automatic Smart Dustbin – Rajan Robotics](%2A%2AAutomatic%20Smart%20Dustbin%20%E2%80%93%20Rajan%20Robotics%2A%2A.png)

## 📜 License
This project is licensed under the MIT License. See the `LICENSE` file for details.
