#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Blink example started");

  // Se la scheda ha un LED RGB integrato (come ESP32-S3 DevKitC-1)
  Serial.printf("RGB LED found on pin %d\n", RGB_BUILTIN);
  // neopixelWrite non richiede pinMode
}

void loop() {
  // Accendi il LED RGB (Rosso)
  // neopixelWrite(pin, rosso, verde, blu) - valori 0-255
  neopixelWrite(RGB_BUILTIN, 64, 0, 0); // Luminosità ridotta (64) per non abbagliare
  Serial.println("LED ON (Red)");
  delay(1000);

  neopixelWrite(RGB_BUILTIN, 0, 64, 0); // Luminosità ridotta (64) per non abbagliare
  Serial.println("LED ON (Green)");
  delay(1000);

  neopixelWrite(RGB_BUILTIN, 0, 0, 64); // Luminosità ridotta (64) per non abbagliare
  Serial.println("LED ON (Blue)");
  delay(1000);

  // Spegni il LED RGB
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);
  Serial.println("LED OFF");
  delay(1000);
}
