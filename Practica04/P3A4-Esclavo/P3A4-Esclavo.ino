// Esclavo
#define led 13

#include <Wire.h>

int dato;

void setup() {
  Wire.begin(0xAF);
  Serial.begin(9600);

  Wire.onReceive(lectura);  
  pinMode(led, OUTPUT);
}

void loop() {
  Serial.println(dato);
  delay(100);
}

void lectura(){
  dato = Wire.read();
  if(dato){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
