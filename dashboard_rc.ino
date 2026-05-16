/*
  RC Dashboard ESP32-C6 V2
  Base firmware untuk telemetry + display
*/

#include <Arduino.h>

// ====== SIMULASI DATA RC ======
float batteryVoltage = 12.6;
int speedKmh = 0;
int signalStrength = 0; // RSSI

// ====== TIMER ======
unsigned long lastUpdate = 0;

// ====== SETUP ======
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== RC DASHBOARD V2 START ===");

  // TODO: init display (TFT_eSPI / LVGL)
  // TODO: init BLE / ESP-NOW / WiFi
}

// ====== LOOP ======
void loop() {
  updateTelemetry();
  updateDisplay();

  delay(200);
}

// ====== UPDATE DATA (SIMULASI) ======
void updateTelemetry() {
  if (millis() - lastUpdate > 500) {
    lastUpdate = millis();

    // simulasi data berubah
    speedKmh = (speedKmh + 3) % 120;
    batteryVoltage -= 0.01;
    if (batteryVoltage < 10.5) batteryVoltage = 12.6;

    signalStrength = random(-90, -30);

    Serial.print("Speed: ");
    Serial.print(speedKmh);
    Serial.print(" km/h | Batt: ");
    Serial.print(batteryVoltage);
    Serial.print("V | RSSI: ");
    Serial.println(signalStrength);
  }
}

// ====== DISPLAY (NANTI DIISI LCD) ======
void updateDisplay() {
  // Placeholder untuk LCD
  // Kalau pakai TFT_eSPI nanti kita isi di sini

  /*
  tft.setCursor(10, 10);
  tft.printf("Speed: %d km/h", speedKmh);

  tft.setCursor(10, 30);
  tft.printf("Batt: %.2f V", batteryVoltage);

  tft.setCursor(10, 50);
  tft.printf("Signal: %d dBm", signalStrength);
  */
}