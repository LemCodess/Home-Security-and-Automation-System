# Home Security & Automation System

A smart home security and automation system integrating multiple sensors and actuators to enhance residential security and automate appliances.

## Demo

[Watch Demo Video](https://drive.google.com/file/d/1quD_uGFrGuLKI4AUsGi715QqwaGQiwGM/view?usp=sharing)

## Features

### 1. RFID-Based Door Security
- Secure access control using RFID authentication
- Servo motor operates door lock based on authorized card scanning
- Buzzer alerts for unauthorized access attempts

### 2. Automated Fire Detection & Notification
- Real-time fire detection using flame sensor
- Instant WhatsApp notifications via ESP32 module
- Local buzzer alerts for immediate response

### 3. Motion and Temperature-Based Fan Control
- PIR sensor detects room occupancy
- Temperature-based fan speed control (OFF/MEDIUM/HIGH)
- Energy-efficient operation - fan only runs when room is occupied

### 4. Weather-Responsive Clothes Retractor
- Rain sensor automatically detects rainfall
- Servo motor rotates clothes rack to protected position
- Prevents clothes from getting wet without manual intervention


## Setup

1. **Arduino Setup:**
   - Upload `arduino-code.ino` to Arduino Uno
   - Connect sensors and actuators as per circuit diagram in report

2. **ESP32 Setup:**
   - Upload `esp-code.ino` to ESP32 module
   - Configure WiFi credentials in code
   - Set up CallMeBot API for WhatsApp notifications

3. **Power:**
   - Connect appropriate power supply to Arduino and ESP32
   - Ensure sufficient battery capacity for DC motor operation

## Documentation

For detailed information including circuit diagrams, full code, cost breakdown, and challenges faced, please refer to:
- [Full Project Report](CSE461%20Project%20Report.docx.pdf)
- [User Manual](CSE461%20Project%20User%20Manual.docx.pdf)

## Team

**CSE461 - Section 06, Group 04**
- Jannatul Ferdaus
- Anonna Dev Nipa
- Tangena Islam
- Sirajum Munira Lamisa

## Technologies

- Arduino IDE
- ESP32 WiFi Module
- RFID (RC522)
- CallMeBot API for WhatsApp Integration
- I2C LCD Display

---
