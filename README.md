# IoT-Based Smart Floating Waste Detection Using KiwisIoT

## Project Overview

This project is designed to detect floating waste in water bodies using IoT technology. An ESP8266 NodeMCU collects sensor data to identify waste and transmit monitoring information to the KiwisIoT platform. It supports remote monitoring and helps improve water cleanliness and waste management.

## Hardware Components

- ESP8266 NodeMCU
- Waste Detection Sensor
- Jumper Wires
- Power Supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

Sensor connections depend on the hardware configuration used in the project.

## Working Principle

The sensor detects floating waste in the water and provides readings to the ESP8266 NodeMCU. The controller processes the sensor data and sends the information to the KiwisIoT platform for remote monitoring through an IoT dashboard.

## KiwisIoT Dashboard

The dashboard displays waste detection information and sensor readings for remote monitoring. The available data channels depend on the sensor configuration used in the project.

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor floating waste detection through the KiwisIoT dashboard.

## Applications

- Floating waste detection
- Smart water waste management
- Lake and pond monitoring
- River cleanliness monitoring
- Water pollution management

## Project Reference

**Hackster.io Project:**  
[https://www.hackster.io/harispidy07/iot-based-smart-floating-waste-detection-using-kiwisiot-dd8574](https://www.hackster.io/harispidy07/iot-based-smart-floating-waste-detection-using-kiwisiot-dd8574)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Built using ESP8266 and KiwisIoT for smart floating waste detection and water management._
