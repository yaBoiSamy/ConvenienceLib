// Library testing file

#include "ConvenienceLib.h"

Vect u(1, 2, 3);
Vect v(4, 5, 6);

void setup() {
  Serial.begin(115200);
  delay(500);
}

void loop() {
  Serial.println("sussy");
  Serial.println(u.str());
  Serial.println(u.x());
  Serial.println(u.y());
  Serial.println(u.z());
  Serial.println(u.norm());
  Serial.println(u.angle(v));
  Serial.println(u.normalize().str());
  Serial.println(u.dot(v));
  Vect cross = u.cross(v);
  Serial.println(cross.str());
  Serial.println(cross.dot(u));
  Serial.println(cross.dot(v));

  delay(1000);
}
