# Technical Specifications and Design Notes

This document outlines the detailed technical specifications, design decisions, and implementation details for the IoT Heart Rate Monitoring System project.

---

## 1. System Overview

**Objective:**
Develop a reliable, low-cost IoT device to measure heart rate (BPM) and SpO₂, transmit data to the cloud via Wi-Fi, and enable anomaly detection using machine learning.

**Core Components:**

* Sensor module: MAX30100 or equivalent pulse oximeter
* Microcontroller: ESP8266 (NodeMCU)
* Power: USB 5V
* Cloud platform: Blynk IoT
* ML backend: Python (Jupyter, scikit-learn)

---

## 2. Hardware Specifications

| Component         | Specification                  | Notes                                  |
| ----------------- | ------------------------------ | -------------------------------------- |
| MAX30100 Sensor   | Operating voltage: 1.8–3.3V    | I2C interface                          |
| ESP8266 (NodeMCU) | 80–160 MHz, 3.3V               | Wi-Fi 802.11b/g/n                      |
| Power Supply      | 5V USB or 9V battery (via VIN) | Regulated 3.3V onboard                 |
| Breadboard / PCB  | Standard 2.54 mm pitch         | Prototype vs. custom PCB               |
| Connecting Wires  | DuPont cables, 20–30 AWG       | Use shielded wires for noise reduction |

---

## 3. Software Specifications

### 3.1 Arduino Firmware

* **Language:** C++ (Arduino)
* **Libraries:**

  * `Blynk` (v1.0.0+)
  * `MAX30100_PulseOximeter` (v1.1.0+)
* **Features:**

  * Sensor initialization and data acquisition
  * Wi-Fi configuration and reconnection logic
  * Blynk data streaming and notifications
  * Error handling for sensor and network failures

### 3.2 Data Format

* **Sample structure (JSON over Blynk):**

  ```json
  {
    "timestamp": "2025-05-07T10:00:00Z",
    "bpm": 78,
    "spo2": 96
  }
  ```
* **CSV Logging (ML):**

  ```csv
  timestamp,bpm,spo2
  2025-01-01 08:00:00,78,96
  ```

### 3.3 ML Module

* **Environment:** Python 3.8+ in virtualenv
* **Libraries:**

  * `numpy`, `pandas`
  * `scikit-learn`
  * `jupyter`
* **Algorithms:** Isolation Forest (for anomaly detection), placeholder for LSTM.

---

## 4. Communication Protocols

* **I2C** between ESP8266 and MAX30100 (400 kHz)
* **Wi-Fi** (802.11b/g/n) to Blynk
* **Data Transport:** MQTT over WebSockets via Blynk library

---

## 5. Design Considerations

* **Power Efficiency:** Deep sleep between readings
* **Accuracy:** Calibration routine on startup
* **Reliability:** Retry mechanisms for network dropouts
* **Security:** Token-based authentication (Blynk Auth Token)

---

## 6. Future Enhancements

* Add onboard display (OLED)
* Implement LSTM-based predictive model
* Secure data storage (SSL/TLS)
* Mobile app integration beyond Blynk
