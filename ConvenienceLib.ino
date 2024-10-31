// Library testing file

#include "ConvenienceLib.h"

Button butt(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(butt.read());
}
