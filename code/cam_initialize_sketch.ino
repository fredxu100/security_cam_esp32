int FLASH_PIN = 4;   // LED flash pin on ESP32-CAM
int INTERVAL = 3000;

unsigned int pt = 0;

void setup() {
  Serial.begin(115200);   // USB serial
  Serial1.begin(115200, SERIAL_8N1, 21, 20); // UART1 to ESP32-CAM: RX=21, TX=20
  
  pinMode(FLASH_PIN, OUTPUT);
  digitalWrite(FLASH_PIN, HIGH);
  
}

void loop() {

  /*unsigned int t = millis();

  if (t - pt >= INTERVAL)
  {
    pt = t;
    digitalWrite(FLASH_PIN, HIGH);
    digitalWrite(FLASH_PIN, LOW);
  }*/

  // Forward data from USB to ESP32-CAM
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
  // Forward data from ESP32-CAM to USB
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}