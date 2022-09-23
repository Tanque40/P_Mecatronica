#define POT A0
#define S_LED 13

float value = 0;
float voltaje = 0;

void setup() {
    pinMode(S_LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    value = analogRead(POT);
    voltaje = value / 1023 * 5;
    Serial.print("Voltaje: ");
    Serial.println(voltaje);
    if (voltaje > 3.0)
        digitalWrite(S_LED, HIGH);
    else
        digitalWrite(S_LED, LOW);
    delay(200);
}
