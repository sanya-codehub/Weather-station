#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

void setup() {
    Serial.begin(115200);

    dht.begin();

    Wire.begin(21, 22);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED error!");
        while (true);
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(2);
    display.setCursor(10, 20);
    display.println("Weather");
    display.display();

    delay(1500);
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("WEATHER STATION");
    display.drawLine(0, 12, 127, 12, SSD1306_WHITE);

    if (isnan(temperature) || isnan(humidity)) {
        display.setCursor(0, 25);
        display.println("Sensor error!");
    } else {
        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Temperature:");

        display.setTextSize(2);
        display.setCursor(0, 30);
        display.print(temperature, 1);
        display.println(" C");

        display.setTextSize(1);
        display.setCursor(0, 52);
        display.print("Humidity: ");
        display.print(humidity, 0);
        display.println("%");
    }

    display.display();

    delay(2000);
}




