#define LED 13
#define BTN 12

int buttonState;

void setup() {
  //Para configurar el pin 13 como lo voy a usar, hay 2 estados, alto o bajo y es salida o entrada.
  //Si quiero encender el LED es salida
  pinMode (LED, OUTPUT); //(pin, salida)

  pinMode (BTN, INPUT); //(pin, entrada)
}

void loop() {
  buttonState = digitalRead(BTN);
  if(buttonState){
    // Rutina de 4 Hertz
    digitalWrite(LED, HIGH); //HIGH funciona como un 1
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
  } else {
    // Rutina de 1 Hertz
    digitalWrite(LED, HIGH); //HIGH funciona como un 1
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
}