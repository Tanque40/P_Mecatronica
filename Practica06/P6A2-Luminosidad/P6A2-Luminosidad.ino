#define entradaVoltimetro A0
#define RedLed 7

// Minimo: valor bits: 85
// Máximo: valor bits: 1011

float voltaje;
int pwm;

void setup() {
  Serial.begin(9600);

  pinMode(RedLed, OUTPUT);
}

void loop() {
  voltaje = analogRead(entradaVoltimetro);
  pwm = map(voltaje, 85, 1011, 255, 0);
  pwm = pwm / 4;
  analogWrite(RedLed, pwm);
  Serial.print("Voltaje: ");
  Serial.println(voltaje);
  
  delay(1000);
}
