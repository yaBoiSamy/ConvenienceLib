#include "ConvenienceLib.h"

ArduinoButton butt(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(butt.read());
}
