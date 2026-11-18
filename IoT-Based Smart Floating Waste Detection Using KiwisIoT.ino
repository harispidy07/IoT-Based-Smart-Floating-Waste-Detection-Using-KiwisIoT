#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Sensor Pins
#define IR_PIN D5
#define TRIG_PIN D6
#define ECHO_PIN D7

// Collection Container Height
const float BIN_HEIGHT_CM = 30.0;

// Waste Detection Threshold
const float FULL_LEVEL_CM = 8.0;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;
unsigned long lastDetection = 0;

unsigned long wasteCount = 0;

bool previousIRState = HIGH;

float readDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
    pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2.0;
}

void setup() {

  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  kiwisiot.begin();

  Serial.println("Floating Waste Detection Started");
}

void loop() {

  kiwisiot.run();

  // Read IR Sensor
  bool currentIRState = digitalRead(IR_PIN);

  // Detect a new object
  if (currentIRState == LOW &&
      previousIRState == HIGH &&
      millis() - lastDetection > 1000) {

    wasteCount++;

    lastDetection = millis();

    Serial.println("Floating Waste Detected!");
    Serial.print("Waste Count: ");
    Serial.println(wasteCount);
  }

  previousIRState = currentIRState;

  // Monitor collection container
  if (millis() - previousMillis >= 3000) {

    previousMillis = millis();

    float distance = readDistance();

    Serial.println("\\n--- FLOATING WASTE MONITOR ---");

    if (distance > 0 &&
        distance <= BIN_HEIGHT_CM) {

      float filledLevel =
        BIN_HEIGHT_CM - distance;

      String collectionStatus =
        (distance <= FULL_LEVEL_CM)
        ? "BIN FULL"
        : "NORMAL";

      Serial.print("Waste Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      Serial.print("Collection Level: ");
      Serial.print(filledLevel);
      Serial.println(" cm");

      Serial.print("Waste Count: ");
      Serial.println(wasteCount);

      Serial.print("Collection Status: ");
      Serial.println(collectionStatus);

      // Send information to KiwisIoT
      kiwisiot.send("0", String(wasteCount));

      kiwisiot.send("1", String(distance, 2));

      kiwisiot.send("2", String(filledLevel, 2));

      kiwisiot.send("3", collectionStatus);

    } else {

      Serial.println("Invalid Ultrasonic Reading");

    }
  }
}