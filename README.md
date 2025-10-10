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

## 🪛 Setup & Upload

1. Open the `.ino` file in **Arduino IDE**.  
2. Select **DFRobot FireBeetle ESP32-C6** as the board.  
3. Install required libraries:  
   - `WiFi.h`  
   - `NTPClient.h`  
   - `Adafruit_GFX.h`  
   - `Adafruit_SSD1306.h`  
   - `Adafruit_SHTC3.h`  
4. Enter your **Wi-Fi credentials** in the code.  
5. Upload and enjoy your space-themed IoT clock!

---

## 🧠 Inspiration

Satellites orbit our planet to maintain global time accuracy — OrbitClock brings that same precision and wonder to your desk.  
Every time you glance at it, it’s a small reminder of how technology and creativity can orbit together in harmony.

---

## 🏗️ Designed & Built By

**Kishan Pratap Singh**  
Founder & CEO of **SMART BUILD**

🌐 **Official Links:**  
- 🔗 [Instructables](https://www.instructables.com/member/Next%20Builder%20DIY/)  
- 💡 [Hackster.io](https://hackster.io/NEXTBUILDER)  
- ⚙️ [Hackaday](https://hackaday.io/NextBuilder)  
- 🤖 [DFRobot Community](https://community.dfrobot.com/user-13435.html)  
- 🎥 [YouTube – Next Builder](https://youtube.com/@NextBuilder)  
- 📷 [Instagram – @next_builder](https://instagram.com/next_builder)

---

## 📜 License

This project is open-source under the **MIT License**.  
You are free to explore, modify, and share your own version of OrbitClock!

---

> 💬 *Share your build — tag me on social media! I’d love to see your version of OrbitClock orbiting your workspace.*
