#include "AS5147U.h"

AS5147U::AS5147U(uint8_t csPin) : csPin(csPin) {}

void AS5147U::begin() {
    pinMode(csPin, OUTPUT);
    digitalWrite(csPin, HIGH);
    SPI.begin();
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
}

uint16_t AS5147U::getAngle() {
    return readRegister(0x3FFF) & 0x3FFF;
}

float AS5147U::readAngleDegree() {
    return (float(getAngle()) * 360.0f) / 16384.0f;
}




float AS5147U::getCumulativeAngle() {
    float currentRawAngle = readAngleDegree();
    float delta = currentRawAngle - lastRawAngle;

    // wrap detection
    if (delta < -180.0f) {
        delta += 360.0f;
    } else if (delta > 180.0f) {
        delta -= 360.0f;
    }

    cumulativeAngle += delta;
    lastRawAngle    = currentRawAngle;
    return cumulativeAngle;
}


int16_t AS5147U::getVelocity() {
    uint16_t raw = readRegister(0x3FFC) & 0x3FFF;
    // Convert from 14-bit signed to int16
    if (raw & 0x2000) raw |= 0xC000; // Sign extend
    return static_cast<int16_t>(raw);
}


uint16_t AS5147U::readRegister(uint16_t address) {
    uint16_t command = buildCommand(address, true);

    digitalWrite(csPin, LOW);
    SPI.transfer16(command); // Send command
    digitalWrite(csPin, HIGH);

    delayMicroseconds(1); // Short delay between transfers

    digitalWrite(csPin, LOW);
    uint16_t response = SPI.transfer16(0x0000); // Dummy write to receive
    digitalWrite(csPin, HIGH);

    if (response & 0x4000) {
        //Serial.println("AS5147U Error: EF bit set in response!");
    }

    return response;
} 


uint16_t AS5147U::buildCommand(uint16_t address, bool read) {
    uint16_t command = ((address & 0x3FFF) << 2) | (read ? 0x0002 : 0x0000);
    if (evenParity(command)) {
        command |= 0x0001;
    }
    return command;
}

uint8_t AS5147U::evenParity(uint16_t value) {
    uint8_t count = 0;
    for (uint8_t i = 0; i < 16; i++) {
        count += (value >> i) & 0x01;
    }
    return count % 2;
}