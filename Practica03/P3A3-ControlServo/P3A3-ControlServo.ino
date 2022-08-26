#include <Servo.h>

#define POT A0

Servo servo1;

float value = 0;
int angulo;

void setup() {
  servo1.attach(7);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(POT);
  angulo = map(value, 0, 1023, 0, 180);
  servo1.write(angulo);
  delay(100);
}
