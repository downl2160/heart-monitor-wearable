# IoT Heart Rate Monitoring System

A smart health monitoring device that measures heart rate (BPM) and blood oxygen saturation (SpO2) using the MAX30100 sensor and ESP8266, and visualizes data on the Blynk IoT platform. This repository also includes a starter template for integrating basic Machine Learning modules for anomaly detection and predictive insights on recorded heart rate data.

---

## Table of Contents

* [Features](#features)
* [Hardware Requirements](#hardware-requirements)
* [Software Requirements](#software-requirements)
* [Project Structure](#project-structure)
* [Installation](#installation)
* [Usage](#usage)
* [Machine Learning Integration](#machine-learning-integration)
* [Contributing](#contributing)
* [License](#license)

---

## Features

* Real-time heart rate (BPM) and SpO2 monitoring
* Threshold-based alerts via Blynk notifications
* Sample data collection for offline analysis
* Jupyter notebook template for anomaly detection in heart rate data

---

## Hardware Requirements

* MAX30100 Pulse Oximeter Sensor
* ESP8266 (NodeMCU) module
* Heartbeat sensor (optional alternative)
* Power supply (USB or 9V battery)
* Connecting wires, breadboard/PCB
* Optional: LCD display for local readout

---

## Software Requirements

* Arduino IDE (Board: ESP8266)
* Blynk library for Arduino
* (optionally) Python 3.8+ with:

  * `numpy`, `pandas`
  * `scikit-learn`
  * `jupyter`

---

## Project Structure

```
├── LICENSE
├── README.md            # Project overview and setup instructions
├── .gitignore           # Ignored files (build artifacts, secrets)
├── hardware/            # All hardware-related files
│   ├── HEART.ino        # Arduino sketch for sensor + Blynk integration
│   └── circuit_diagram.png
├── assets/              # Images, screenshots, demo results
│   ├── result.jpg
│   └── blynk_console.png
├── ml/                  # Starter ML integration
│   ├── data/
│   │   └── sample_heart_rate.csv
│   └── notebooks/
│       └── anomaly_detection.ipynb
├── docs/                # Detailed specs and design notes
│   └── technical_specifications.md
└── .github/             # CI, workflows, issue templates
    └── ISSUE_TEMPLATE.md
```

---

## Installation

1. **Clone the repository**

   ```bash
   git clone https://github.com/<your-username>/iot-heart-monitor.git
   cd iot-heart-monitor
   ```

2. **Set up Arduino**

   * Open `hardware/HEART.ino` in Arduino IDE
   * Install required libraries (`Blynk`, `MAX30100_PulseOximeter`)
   * Enter your WiFi & Blynk credentials
   * Upload to ESP8266

3. **Python & ML (optional)**

   ```bash
   python3 -m venv venv
   source venv/bin/activate
   pip install -r ml/requirements.txt
   ```

---

## Usage

* Power your ESP8266 and heart rate sensor setup.
* Launch Blynk app and add the `heart2` device (use your template ID and auth token).
* Monitor live data on the Blynk dashboard or collect CSV logs in `ml/data/`.
* Run the Jupyter notebook for anomaly detection:

  ```bash
  jupyter notebook ml/notebooks/anomaly_detection.ipynb
  ```

---

## Machine Learning Integration

This section provides a starter template for applying simple anomaly-detection algorithms (e.g., Isolation Forest) to your collected heart rate time series. Feel free to extend or replace with more advanced models (LSTM autoencoders, ARIMA, etc.).

---

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/your-feature`)
3. Commit your changes (`git commit -m "Add new feature"`)
4. Push to the branch (`git push origin feature/your-feature`)
5. Open a Pull Request

---

## License

Distributed under the MIT License. See [`LICENSE`](./LICENSE) for more information.
