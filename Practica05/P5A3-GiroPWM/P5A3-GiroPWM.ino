#define POT A0
#define MotA 10
#define MotB 11
#define Pwm 9

float POTValue;
int voltajeLeido, SuministroPWM;

void setup() {
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
  pinMode(Pwm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  POTValue = analogRead(POT);
  voltajeLeido = map(POTValue, 0, 1023, 0, 5);

  if( 0 < voltajeLeido && voltajeLeido < 2){
    SuministroPWM = map(POTValue,410,0,0,255);
    doLevoGiro();
  } else if(2 <= voltajeLeido && voltajeLeido <= 3){
    doStop();
  } else if(3 < voltajeLeido && voltajeLeido <= 5) {
    SuministroPWM = map(POTValue,615,1023,0,255);
    doDextroGiro();
  }

  analogWrite(Pwm, SuministroPWM);

  Serial.print("Vol: ");
  Serial.println(voltajeLeido);
  Serial.print("PWM: ");
  Serial.println(SuministroPWM);
  
  delay(1000);
}

void doLevoGiro(){
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.println("Levogiro");
}

void doDextroGiro(){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.println("Dextrogiro");
}

void doStop(){
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, HIGH);
  Serial.println("Detenido");
}
