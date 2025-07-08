# ASX047U - Arduino Library

![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/jonas-merkle/AS5047P/Arduino-Library-CI.yml?branch=master&label=build%20master) ![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/jonas-merkle/AS5047P/Arduino-Library-CI.yml?branch=develop&label=build%20develop) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/jonas-merkle/AS5047P) ![GitHub](https://img.shields.io/github/license/jonas-merkle/AS5047P) ![GitHub issues](https://img.shields.io/github/issues/jonas-merkle/AS5047P) ![GitHub pull requests](https://img.shields.io/github/issues-pr/jonas-merkle/AS5047P) ![Maintenance](https://img.shields.io/maintenance/yes/2025)

## Overview

The **AS5X47U Arduino Library** provides an easy way to interface with the AS5047P high-resolution rotary position sensor, as well as several other sensors from the AS5x47 series. This library supports reading the angular position and other diagnostic information using SPI communication, and is designed to work with a variety of microcontrollers, including Arduino, Adafruit Feather, and Teensy boards.

The AS5047P sensor provides high-resolution rotary position sensing with a 14-bit resolution, making it ideal for applications that require accurate angular measurements, such as robotics, motor control, and industrial automation.

## Features

- Support for multiple sensor models: AS5047U, AS5147U, and AS5247U.
- Easy-to-use interface for reading angular position.
- SPI communication for reliable data transmission.
  
## Contents

- [AS5047U - Arduino Library](#as5047p---arduino-library)
  - [Overview](#overview)
  - [Features](#features)
  - [Contents](#contents)
  - [Supported Sensors](#supported-sensors)
  - [Documentation](#documentation)
  - [Installation Instructions](#installation-instructions)
    - [Install via Arduino Library Manager](#install-via-arduino-library-manager)
    - [Manual Installation](#manual-installation)
    - [Install via PlatformIO Library Manager](#install-via-platformio-library-manager)
  - [Connecting the AS5047P to Your Arduino](#connecting-the-as5047p-to-your-arduino)
    - [Arduino Uno](#arduino-uno)
    - [Arduino Mega](#arduino-mega)
    - [Adafruit Feather M0](#adafruit-feather-m0)
    - [Teensy Board Connections](#teensy-board-connections)
      - [Teensy 3.5](#teensy-35)
      - [Teensy 3.6](#teensy-36)
      - [Teensy 4.0](#teensy-40)
      - [Teensy 4.1](#teensy-41)
  - [Usage Guide](#usage-guide)
    - [Basic Example](#basic-example)
    - [Advanced Usage](#advanced-usage)
  - [License](#license)
  - [Project Status \& To-Do's](#project-status--to-dos)

## Supported Sensors

The following sensors of the **AS5x47** series of rotary position sensors are supported by this library:

- [AS5047U](https://ams.com/documents/20143/36005/AS5047U_DS000637_1-00.pdf/8639418f-6c3a-1624-4e6f-18f52c962099)
- [AS5147U](https://ams.com/documents/20143/36005/AS5147U_AS5247U_DS000639_4-00.pdf/1141a423-d438-ff83-df65-0adc533d6801)
- [AS5247U](https://ams.com/documents/20143/36005/AS5147U_AS5247U_DS000639_4-00.pdf/1141a423-d438-ff83-df65-0adc533d6801)

## Documentation

The library documentation is deployed on GitHub Pages. For detailed reference on the API, examples, and usage guides, check the links below:

| Branch | Link |
|--------|------|
| Master | [Documentation](https://jonas-merkle.github.io/AS5047P/docs/master/html/index.html) |
| Develop | [Documentation](https://jonas-merkle.github.io/AS5047P/docs/develop/html/index.html) |

## Installation Instructions

### Install via Arduino Library Manager

The easiest way to install this library is to use the built-in Arduino Library Manager:

1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries...**
3. In the Library Manager, type `AS5047U` in the search bar.
4. Install the latest version of the library.

You can also upgrade the library to the newest release via the Arduino Library Manager. For more information, refer to the [Arduino Libraries Guide](https://www.arduino.cc/en/guide/libraries). Note that you need at least version 1.6.2 of the Arduino IDE to use the Library Manager.

### Manual Installation

1. Download the latest version of the library from [GitHub Releases](https://github.com/jonas-merkle/AS5047P/releases).
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to your Arduino libraries directory (e.g., `Documents/Arduino/libraries`).

Follow the [Arduino Libraries Guide](https://www.arduino.cc/en/guide/libraries) for more detailed instructions.

### Install via PlatformIO Library Manager

To add this library to your PlatformIO project, follow these steps:

1. Open PlatformIO IDE.
2. Search for `AS5047P` in the Library Manager UI, or run the following command in the PlatformIO CLI:
   ```
   pio lib install "jonas-merkle/AS5047P"
   ```

## Connecting the AS5047P to Your Arduino

### Arduino Uno

| AS5047U Pin | Arduino Uno Pin | Comment |
|:-----------:|:---------------:|:--------|
| GND         | GND             | Ground connection |
| VDD         | 5V              | Power supply (5V) |
| VDD3V       | NC              | Not connected     |
| MOSI        | MOSI (Pin: 11)  | SPI Data Out      |
| MISO        | MISO (Pin: 12)  | SPI Data In       |
| CLK         | SCK (Pin: 13)   | SPI Clock         |
| CSn         | 9               | Chip select (configurable pin) |

### Arduino Mega

| AS5047U Pin | Arduino Mega Pin | Comment |
|:-----------:|:----------------:|:--------|
| GND         | GND              | Ground connection |
| VDD         | 5V               | Power supply (5V) |
| VDD3V       | NC               | Not connected     |
| MOSI        | MOSI (Pin: 51)   | SPI Data Out      |
| MISO        | MISO (Pin: 50)   | SPI Data In       |
| CLK         | SCK (Pin: 52)    | SPI Clock         |
| CSn         | 9                | Chip select (configurable pin) |

### Adafruit Feather M0

| AS5047U Pin | Adafruit Feather M0 Pin | Comment |
|:-----------:|:-----------------------:|:--------|
| GND         | GND                     | Ground connection |
| VDD         | 3V                      | Power supply (3.3V) |
| VDD3V       | 3V                      | Power supply (3.3V) |
| MOSI        | MOSI                    | SPI Data Out       |
| MISO        | MISO                    | SPI Data In        |
| CLK         | SCK                     | SPI Clock          |
| CSn         | 9                       | Chip select (configurable pin) |

**Warning: Ensure the sensor is powered with 3.3V to avoid damage to the Adafruit Feather M0 board.**

### Teensy Board Connections

#### Teensy 3.5

| AS5047U Pin | Teensy Pin      | Comment |
|:-----------:|:---------------:|:--------|
| GND         | GND             | Ground connection |
| VDD         | 3V              | Power supply (3.3V) |
| VDD3V       | 3V              | Power supply (3.3V) |
| MOSI        | MOSI0 (Pin: 11) | SPI Data Out       |
| MISO        | MISO0 (Pin: 12) | SPI Data In        |
| CLK         | SCK0 (Pin: 13)  | SPI Clock          |
| CSn         | CS0 (Pin: 10)   | Chip select (configurable pin) |

**Warning: Ensure the sensor is powered with 3.3V to avoid damage to the Teensy board.**

#### Teensy 3.6

| AS5047U Pin | Teensy Pin      | Comment |
|:-----------:|:---------------:|:--------|
| GND         | GND             | Ground connection |
| VDD         | 3V              | Power supply (3.3V) |
| VDD3V       | 3V              | Power supply (3.3V) |
| MOSI        | MOSI0 (Pin: 11) | SPI Data Out       |
| MISO        | MISO0 (Pin: 12) | SPI Data In        |
| CLK         | SCK0 (Pin: 13)  | SPI Clock          |
| CSn         | CS0 (Pin: 10)   | Chip select (configurable pin) |

**Warning: Ensure the sensor is powered with 3.3V to avoid damage to the Teensy board.**

#### Teensy 4.0

| AS5047U Pin | Teensy Pin      | Comment |
|:-----------:|:---------------:|:--------|
| GND         | GND             | Ground connection |
| VDD         | 3V              | Power supply (3.3V) |
| VDD3V       | 3V              | Power supply (3.3V) |
| MOSI        | MOSI (Pin: 11)  | SPI Data Out       |
| MISO        | MISO (Pin: 12)  | SPI Data In        |
| CLK         | SCK (Pin: 13)   | SPI Clock          |
| CSn         | CS (Pin: 10)    | Chip select (configurable pin) |

**Warning: Ensure the sensor is powered with 3.3V to avoid damage to the Teensy board.**

#### Teensy 4.1

| AS5047U Pin | Teensy Pin      | Comment |
|:-----------:|:---------------:|:--------|
| GND         | GND             | Ground connection |
| VDD         | 3V              | Power supply (3.3V) |
| VDD3V       | 3V              | Power supply (3.3V) |
| MOSI        | MOSI (Pin: 11)  | SPI Data Out       |
| MISO        | MISO (Pin: 12)  | SPI Data In        |
| CLK         | SCK (Pin: 13)   | SPI Clock          |
| CSn         | CS (Pin: 10)    | Chip select (configurable pin) |

**Warning: Ensure the sensor is powered with 3.3V to avoid damage to the Teensy board.**

### Basic Example

The following example demonstrates how to read the angle from the AS5047U sensor using an Arduino board.

```cpp
#include <SPI.h>
#include <AS5047U.h>

AS5047P sensor(9); // Chip select pin 9

void setup() {
  Serial.begin(9600);
  SPI.begin();
  sensor.initSPI();
}

void loop() {
  uint16_t angle = sensor.readAngle();
  Serial.print("Angle: ");
  Serial.println(angle);
  delay(500);
}
```

