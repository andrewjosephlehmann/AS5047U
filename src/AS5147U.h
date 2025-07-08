#ifndef AS5147U_H
#define AS5147U_H

#include <Arduino.h>
#include <SPI.h>

class AS5147U {
public:
    AS5147U(uint8_t csPin);
    void begin();
    uint16_t getAngle();
    float readAngleDegree();
    float getCumulativeAngle();
    int16_t getVelocity(); // Signed 14-bit value

private:
    uint8_t csPin;
    uint16_t readRegister(uint16_t address);
    uint16_t buildCommand(uint16_t address, bool read);
    uint8_t evenParity(uint16_t value);
    float cumulativeAngle = 0.0f;
    float lastRawAngle = 0.0f;
};

#endif