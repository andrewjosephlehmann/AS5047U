#include "AS5147U.h"

AS5147U sensor(10); // CS on pin 10

void setup() {
    Serial.begin(115200);
    sensor.begin();
}

void loop() {
    uint16_t angle = sensor.getAngle();
    int16_t velocity = sensor.getVelocity();

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" | Velocity: ");
    Serial.println(velocity);

    delay(100);
}