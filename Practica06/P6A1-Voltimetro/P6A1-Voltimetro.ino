#define entradaVoltimetro A0
#define RedLed 7

// Minimo: 6.4v, valor bits: 667
// Promedio: 7.4v, valor bits: 771
// Máximo: 8.4v, valor bits: 875

float voltaje;

void setup() {
  Serial.begin(9600);

  pinMode(RedLed, OUTPUT);
}

void loop() {
  voltaje = analogRead(entradaVoltimetro);
  if(voltaje <= 667){
    digitalWrite(RedLed, HIGH);
  } else if(voltaje > 667 && voltaje <= 875) {
    digitalWrite(RedLed, HIGH);
    delay(250);
    digitalWrite(RedLed, LOW);
    delay(250);
  }
  Serial.print("Voltaje: ");
  Serial.println(voltaje);
  
  delay(1000);
}
