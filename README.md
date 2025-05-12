# RFID-Based Attendance System Using Arduino

This project implements an RFID-based attendance system that automates tracking of students' or employees' presence. It uses RFID cards for identification and logs attendance with date and time. An optional GSM module can be used to send SMS notifications in real time.

## 👤 Presented by
**Chanchal Bhardwaj (21dcs020)**  
**Guide:** Dr. Robin Singh Bhadoria

---

## 🧠 Project Overview

Each user scans an RFID card to mark their attendance. The system:
- Displays access status on an LCD
- Logs the attendance in an SD card
- Provides audio/visual feedback using a buzzer and LEDs
- Optionally sends SMS alerts via GSM module

---

## 🛠️ System Architecture

1. **RFID Reader Module (RC522)** – Reads card and sends unique ID to Arduino  
2. **Arduino Uno** – Main controller, handles logic  
3. **RTC Module (DS3231)** – Provides real-time clock  
4. **SD Card Module** – Stores attendance logs  
5. **16x2 LCD** – Displays messages  
6. **Buzzer + LEDs** – Feedback for valid/invalid scans  
7. *(Optional)* **GSM Module** – Sends SMS notifications

---

## 🔩 Hardware Components

- Arduino Uno  
- RFID Reader (RC522 or EM-18)  
- RFID Tags/Cards  
- RTC Module (DS3231)  
- SD Card Module  
- 16x2 LCD Display  
- Buzzer  
- Green & Red LEDs  
- Breadboard & Jumper Wires  
- *(Optional)* GSM Module

---

## 💻 Software Components

- **Arduino IDE** – To write and upload code  
- **Libraries:**
  - MFRC522
  - RTClib
  - SD
  - LiquidCrystal

---

## 📚 References

- Shoewu et al. (2015) – Automated RFID attendance tracking system  
- Sumita Nainan et al. (2013) – RFID in educational institutions  
- Chakraborty et al. (2024) – Secure RFID logging with SD card and RTC  
- Kashif Ishaq & Samra Bibi (2023) – IoT RFID anti-proxy systems

---

## 📬 Thank You!
