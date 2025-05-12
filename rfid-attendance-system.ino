#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
#include <SD.h>

// Pin configuration
#define RST_PIN         9
#define SS_PIN          10
#define SD_CS_PIN       4
#define BUZZER_PIN      6
#define GREEN_LED       7
#define RED_LED         8

MFRC522 mfrc522(SS_PIN, RST_PIN);
RTC_DS3231 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
File logFile;

String validIDs[] = {"ABC12345", "XYZ67890"};  // Add authorized RFID card UIDs here

void setup() {
  Serial.begin(9600);
  SPI.begin();

  // RFID
  mfrc522.PCD_Init();
  
  // RTC
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }

  // LCD
  lcd.begin(16, 2);
  lcd.print("Scan your card");

  // SD Card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card failed");
    lcd.clear();
    lcd.print("SD card error");
    while (1);
  }

  // Buzzer & LEDs
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  Serial.println("Scanned UID: " + uid);
  mfrc522.PICC_HaltA();

  DateTime now = rtc.now();
  String timestamp = String(now.year()) + "-" + String(now.month()) + "-" + String(now.day()) +
                     " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());

  bool authorized = false;
  for (String id : validIDs) {
    if (uid == id) {
      authorized = true;
      break;
    }
  }

  if (authorized) {
    logAttendance(uid, timestamp);
    showMessage("Access Granted", GREEN_LED, true);
    // sendSMS("Access granted to " + uid); // Uncomment if GSM is added
  } else {
    showMessage("Access Denied", RED_LED, false);
  }
}

void showMessage(String message, int ledPin, bool isAuthorized) {
  digitalWrite(ledPin, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  lcd.clear();
  lcd.print(message);
  delay(2000);
  digitalWrite(ledPin, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  lcd.clear();
  lcd.print("Scan your card");
}

void logAttendance(String uid, String time) {
  logFile = SD.open("attendance.txt", FILE_WRITE);
  if (logFile) {
    logFile.println(uid + "," + time);
    logFile.close();
    Serial.println("Logged: " + uid + "," + time);
  } else {
    Serial.println("Failed to write log");
  }
}

// Optional SMS function (if GSM module is used)
// void sendSMS(String message) {
//   Serial.println("Sending SMS: " + message);
//   // Add GSM module logic here
// }
