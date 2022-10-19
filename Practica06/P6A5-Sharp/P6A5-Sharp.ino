#include <math.h>
#define light A0
#define LED 8

double valorMedido;
double distancia;

void setup(){
    pinMode(LED, OUTPUT);

    Serial.begin(9600);
}

void loop(){
    valorMedido = analogRead(light);

    distancia = 7391.9 * pow(valorMedido, -1.219);

    if(distancia < 15.0){
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }
  
    Serial.print(distancia);
    Serial.println("cm");
    delay(500);
}
