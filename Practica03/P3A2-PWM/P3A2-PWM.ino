#define POT A0
#define S_LED 13

float value;
float candelas;

int pwm = 0;

void setup() {
  pinMode(S_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    value = analogRead(POT);
    analogWrite(S_LED, pwm);
    candelas = value / 1023 * 100;
    pwm = value / 4;
    Serial.print("candelas: ");
    Serial.println(candelas);
    delay(10);
}
