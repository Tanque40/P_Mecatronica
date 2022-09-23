#define POT A0
#define MotA 10
#define MotB 11

float POTValue;
int voltajeLeido;

void setup() {
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  POTValue = analogRead(POT);
  voltajeLeido = map(POTValue, 0, 1023, 0.0, 5.0);
  Serial.println(voltajeLeido);
  if( 0 < voltajeLeido && voltajeLeido < 2){
    doLevoGiro();
  } else if(2 <= voltajeLeido && voltajeLeido <= 3){
    doStop();
  } else if(3 < voltajeLeido && voltajeLeido < 5) {
    doDextroGiro();
  }
  
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
