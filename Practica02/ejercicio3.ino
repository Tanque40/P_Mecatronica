#define S1_RED_LED 13
#define S1_YELL_LED 12
#define S1_GREEN_LED 11

#define S2_RED_LED 10
#define S2_YELL_LED 9
#define S2_GREEN_LED 8

int buttonState;

void setup() {
  pinMode (S1_RED_LED, OUTPUT); //(pin, salida)
  pinMode (S1_YELL_LED, OUTPUT); //(pin, salida)
  pinMode (S1_GREEN_LED, OUTPUT); //(pin, salida)

  pinMode (S2_RED_LED, OUTPUT); //(pin, salida)
  pinMode (S2_YELL_LED, OUTPUT); //(pin, salida)
  pinMode (S2_GREEN_LED, OUTPUT); //(pin, salida)
}

void loop() {
  digitalWrite(S1_RED_LED, HIGH);
  digitalWrite(S1_YELL_LED, LOW);
  digitalWrite(S1_GREEN_LED, LOW);

  digitalWrite(S2_RED_LED, LOW);
  digitalWrite(S2_YELL_LED, LOW);
  digitalWrite(S2_GREEN_LED, HIGH);
  delay(5000);

  digitalWrite(S2_RED_LED, LOW);
  digitalWrite(S2_YELL_LED, HIGH);
  digitalWrite(S2_GREEN_LED, LOW);
  delay(1000);

  digitalWrite(S2_RED_LED, HIGH);
  digitalWrite(S2_YELL_LED, LOW);
  digitalWrite(S2_GREEN_LED, LOW);

  digitalWrite(S1_RED_LED, LOW);
  digitalWrite(S1_YELL_LED, LOW);
  digitalWrite(S1_GREEN_LED, HIGH);
  delay(5000);

  digitalWrite(S1_RED_LED, LOW);
  digitalWrite(S1_YELL_LED, HIGH);
  digitalWrite(S1_GREEN_LED, LOW);
  delay(1000);
}