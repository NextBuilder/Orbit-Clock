# 🛰️ OrbitClock – A Mini Satellite-Style Space Clock

> “Inspired by satellites that orbit Earth to keep time in sync — OrbitClock brings space precision to your desk.”

---

## 🌌 Introduction

Time and space are beautifully connected — satellites orbit Earth to keep our clocks synchronized with incredible precision.  
Inspired by this cosmic connection, I created **OrbitClock**, a **mini satellite-style IoT clock** that blends the elegance of space design with the precision of modern electronics.

Designed in **Autodesk Fusion 360**, this tiny gadget looks like a spacecraft that just landed on your desk.  
Powered by the **DFRobot Beetle ESP32-C6**, it connects to Wi-Fi and fetches accurate **NTP time**, just like real satellites communicating with ground stations.

A **0.91-inch OLED display** shows real-time **time, temperature, and humidity**, while the **SHTC3 sensor** provides precise environmental readings.  
The 3D-printed body with **landing-style legs** gives it a futuristic, satellite-like look — making it both functional and decorative.

---

## 🌠 Features

- ⏱️ **Accurate Real-Time Clock** – Fetches precise NTP time over Wi-Fi.  
- 🌡️ **Environment Monitoring** – Displays live temperature and humidity using SHTC3 sensor.  
- 🛰️ **Space-Inspired Design** – 3D printed body with satellite-style legs and display window.  
- ⚡ **Powered by DFRobot Beetle ESP32-C6** – Compact, Wi-Fi 6 ready microcontroller.  
- 💾 **Lightweight, Efficient Code** – Developed using Arduino IDE with Adafruit libraries.  
- 🔋 **Rechargeable** – Runs using a lipo battery, great for desks or workspace setups.

---

## 🧰 Components Used

| Component | Description |
|------------|-------------|
| DFRobot Beetle ESP32-C6 | Main microcontroller for Wi-Fi & processing |
| 0.91" OLED Display (SPI) | Displays time, temperature, and humidity |
| SHTC3 Temperature & Humidity Sensor | Measures environmental data |
| 3D Printed Enclosure | Designed in Fusion 360, inspired by a satellite |
| Lipo Battery| Making it Rechargeable  |

---

## 🧩 How It Works

OrbitClock connects to your **Wi-Fi network** and retrieves the **exact NTP time** from global time servers.  
Simultaneously, the **SHTC3 sensor** measures **temperature and humidity**, and all data is displayed on the OLED screen in real time.

Just like satellites observing Earth, OrbitClock continuously “monitors” your room — syncing time and sensing the environment around you. 🌍✨

---

## 📁 Repository Structure

| Folder / File | Description |
|----------------|-------------|
| [CAD Design](./CAD%20Design) | STL files for the satellite-inspired 3D body. |
| [Circuit Diagram](./Circuit%20Diagram) | Circuit diagram for connecting ESP32-C6, OLED, and SHTC3. |
| [Code](./Code) | Arduino sketch for NTP time sync and sensor data display. |

---
