# Embedded-System-project
RFID-Based Attendance System Using Arduino
Presented by: CHANCHAL BHARDWAJ (21dcs020)
Presented to: Dr. ROBIN SINGH BHADORIA

Table of Contents
Objective of the Project

System Architecture

Hardware Components

Software Components

Implementation Snapshots

References

Project Overview
This project implements an RFID-based attendance system that automates the process of tracking attendance for students or employees. Each individual uses an RFID card to mark their presence, and the system sends an instant SMS notification to a predefined number, such as a parent or supervisor, ensuring real-time updates. This project improves attendance monitoring efficiency and provides a reliable, automated method for real-time tracking.

System Architecture
RFID Reader Module

Scans RFID cards/tags.

Sends the unique ID to the Arduino via serial communication.

Arduino Uno (Microcontroller)

Receives the tag ID from RFID Reader.

Compares it with pre-defined registered IDs.

If not matched: Displays "Unauthorized Access", activates red LED + buzzer.

If matched: Logs attendance to SD card with time & date, displays message on LCD, activates green LED + buzzer, optionally sends SMS via GSM module.

RTC Module (DS3231)

Provides real-time date and time for logging.

Communicates with Arduino via I2C protocol.

SD Card Module

Stores the attendance logs in a text or CSV file.

Connected via SPI pins to Arduino.

LCD Display (16x2)

Displays welcome messages, names (optional), success/failure, and time.

Buzzer & LEDs

Green LED & buzzer = Authorized access.

Red LED & buzzer = Unauthorized attempt.

Hardware Components
Arduino Uno → Acts as the brain of the system; controls all operations.

RFID Reader (e.g., RC522 or EM-18) → Scans RFID cards/tags and sends unique IDs to the Arduino.

RFID Tags/Cards → Unique ID tags assigned to users for attendance marking.

16x2 LCD Display → Displays messages like "Access Granted", "Invalid ID", etc.

RTC Module (DS3231 or DS1307) → Provides current date and time for accurate attendance logging.

SD Card Module → Stores attendance logs in a text or CSV file format.

Buzzer → Gives sound feedback for successful/unsuccessful scans.

LEDs (Green & Red) → Visual feedback: Green = authorized, Red = unauthorized.

Software Components
Arduino IDE

Purpose: To write, compile, and upload code to the Arduino board.

Features: User-friendly interface, built-in serial monitor, supports multiple boards.

MFRC522 Library

Purpose: To communicate with the RC522 RFID reader.

Features: Reads RFID tags, detects card presence, handles authentication.

RTClib Library

Purpose: To interface with the Real-Time Clock (RTC) module.

Features: Retrieves accurate date and time, easy time formatting.

Implementation Snapshots
(Images of implementation would be placed here in a GitHub repo)

References
Shoewu et al. (2015) – Proposed an automated RFID-based attendance system that reduced time and improved accuracy compared to manual systems.

Sumita Nainan et al. (2013) – Explained how RFID technology can streamline attendance tracking in educational institutions.

Chakraborty et al. (2024) – Designed a secure RFID attendance system using Arduino, SD card, and RTC module for efficient logging.

Kashif Ishaq & Samra Bibi (2023) – Reviewed IoT-based RFID systems and emphasized real-time data tracking and anti-proxy measures.
