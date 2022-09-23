#define LED 13

void setup() {
  //Para configurar el pin 13 como lo voy a usar, hay 2 estados, alto o bajo y es salida o entrada.
  //Si quiero encender el LED es salida
  pinMode (LED, OUTPUT); //(pin, salida o entrada)
}

void loop() {
  digitalWrite(LED,HIGH); //HIGH funciona como un 1
  delay(300);
  digitalWrite(LED,LOW);
  delay(300);
}