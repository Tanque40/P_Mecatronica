#define MotA 10
#define MotB 11

void setup() {
  // put your setup code here, to run once:
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Estado 1
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.println("Levogiro");
  delay(1000);

  // Estado 2
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.println("Freno pasivo");
  delay(1000);

  // Estado 3
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.println("Dextrogiro");
  delay(1000);

  // Estado 4
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, HIGH);
  Serial.println("Freno activo");
  delay(1000);
}
