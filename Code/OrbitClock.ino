#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SHTC3.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// ===== WiFi info =====
const char* ssid     = "Airtel_vija_6103";
const char* password = "air36175";

// ===== OLED setup =====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ===== SHTC3 setup =====
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

// ===== NTP setup =====
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // IST: UTC+5:30

// ===== Pins =====
#define LED_PIN 10   // Built-in LED on ESP32-C3

// LED
unsigned long lastBlink = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();  // Default I2C pins for ESP32-C3

  // WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setRotation(1);
  display.display();

  // SHTC3 init
  if (!shtc3.begin()) {
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  }

  // NTP init
  timeClient.begin();

  // LED init
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  timeClient.update();

  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();
  int seconds = timeClient.getSeconds();

  // AM/PM
  bool isPM = false;
  if (hours >= 12) {
    isPM = true;
    if (hours > 12) hours -= 12;
  }
  if (hours == 0) hours = 12;

  // Read sensor
  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);
  float tempC = temp.temperature;
  float hum   = humidity.relative_humidity;

  // Format strings
  char hStr[3], mStr[3], sStr[3];
  sprintf(hStr, "%02d", hours);
  sprintf(mStr, "%02d", minutes);
  sprintf(sStr, "%02d", seconds);

  // ===== OLED =====
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Header - Small "maa" text
  display.setTextSize(1);
  display.setCursor(2, 0);
  display.println("maa");
  display.setCursor(60, 10);
  display.println(isPM ? "PM" : "AM");
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  // hh
  display.setTextSize(2);
  display.setCursor(5, 30);
  display.println(hStr);

  // mm
  display.setTextSize(2);
  display.setCursor(5, 52);
  display.println(mStr);

  // ss
  display.setTextSize(2);
  display.setCursor(5, 72);
  display.println(sStr);

  // --------
  display.drawLine(0, 95, 128, 95, SSD1306_WHITE);

  // Temperature & Humidity (moved 2mm right)
  display.setTextSize(1);
  display.setCursor(7, 105);
  display.print((int)tempC);
  display.print((char)247); // degree symbol
  display.print("C");
  display.setCursor(7, 120);
  display.print((int)hum);
  display.print("%");

  display.display();

  // ===== LED =====
  unsigned long now = millis();
  if (now - lastBlink >= 5000) {  // every 5 seconds
    digitalWrite(LED_PIN, HIGH);
    delay(20);                    // on for 20 ms
    digitalWrite(LED_PIN, LOW);
    lastBlink = now;
    
    // Serial output for debugging
    Serial.print("Time: ");
    Serial.print(hStr);
    Serial.print(":");
    Serial.print(mStr);
    Serial.print(":");
    Serial.print(sStr);
    Serial.print(isPM ? " PM" : " AM");
    Serial.print(" | Temp: ");
    Serial.print(tempC);
    Serial.print("°C | Hum: ");
    Serial.print(hum);
    Serial.println("%");
  }

  delay(200); // reduce CPU load
}