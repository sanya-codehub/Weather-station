# ESP32 Weather Station

A small weather station based on ESP32, DHT11 and a 0.96" OLED display.

The project measures air temperature and humidity and displays the readings on an OLED screen.

## Components

- ESP32 development board
- DHT11 temperature and humidity sensor
- 0.96" OLED display (SSD1306, 128x64, I2C)
- Breadboard and jumper wires

## Connections

### DHT11

| DHT11 | ESP32 |
|---|---|
| VCC | 3V3 |
| DATA | GPIO 4 |
| GND | GND |

### OLED Display

| OLED | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Libraries

- DHT sensor library by Adafruit
- Adafruit Unified Sensor
- Adafruit GFX Library
- Adafruit SSD1306

## Features

- Temperature measurement
- Humidity measurement
- OLED display output
- Automatic readings update every 2 seconds
- Basic sensor error handling

## Development Environment

- PlatformIO
- Visual Studio Code
- Arduino Framework
- C++

## Project Status

**In development.**

More features and improvements are planned.

## License

MIT License
