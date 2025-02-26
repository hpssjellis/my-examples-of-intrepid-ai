#include "Arduino.h"

void setup() {
    Serial.begin(115200);
}

void loop() {
    if (Serial.available()) {
        String myReceived = Serial.readStringUntil('\n');
        Serial.print("Received: ");
        Serial.println(myReceived);
    }
    delay(100);
}
