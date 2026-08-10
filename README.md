# IoT Cloud Smart Lighting System

## Project Overview

This project was developed as part of the MainCrafts Embedded Systems & IoT Internship – Task 4.

The system uses an ESP32 and an LDR sensor to monitor ambient light intensity and automatically control an LED. The LDR data is transmitted through Wi-Fi to the ThingSpeak cloud platform for real-time monitoring.

## Components Used

- ESP32
- LDR Sensor Module
- LED
- 220Ω Resistor
- Wokwi Simulator
- ThingSpeak Cloud Platform

## Circuit Connections

### LDR Sensor

| LDR Module | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| AO | GPIO 34 |
| DO | Not Connected |

### LED

| LED | ESP32 |
|---|---|
| Anode (+) | GPIO 13 through 220Ω resistor |
| Cathode (-) | GND |

## Working Principle

1. The LDR sensor measures the surrounding light intensity.
2. ESP32 reads the analog LDR value through GPIO 34.
3. The system automatically controls the LED according to the light level.
4. ESP32 connects to Wi-Fi using the Wokwi network.
5. The LDR value is sent to ThingSpeak using its API.
6. ThingSpeak displays the received data as a real-time graph.

## Automation Logic

- Dark environment → LED ON
- Bright environment → LED OFF

## Cloud Monitoring

ThingSpeak is used to monitor the LDR sensor data remotely.

The LDR reading is uploaded to **Field 1 – LDR Value**.

## Software and Tools

- Arduino IDE / Arduino C++
- Wokwi Simulator
- ThingSpeak
- ESP32

## Key Learnings

- ESP32 programming
- Wi-Fi connectivity
- LDR sensor interfacing
- IoT cloud integration
- REST API-based data transmission
- Real-time sensor monitoring
- Smart automation

## Author

**Vishal Kumar**

B.Tech – Electronics & Communication Engineering

MainCrafts Embedded Systems & IoT Internship
