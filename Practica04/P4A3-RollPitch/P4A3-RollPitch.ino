#include <math.h>
#ifndef MPI
#define MPI 3.14159265358979323846
#endif


#define anX A0
#define anY A1
#define anZ A2

float valueX, valueY, valueZ;

float z_min = 270.0;
float z_max = 400.0;
float zG;

float y_min = 270.0;
float y_max = 400.0;
float yG;

float x_min = 270.0;
float x_max = 400.0;
float xG;

float alfa, beta;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valueX = analogRead(anX);
  valueY = analogRead(anY);
  valueZ = analogRead(anZ);

  zG = map(valueZ, z_min, z_max, -100, 100);
  zG = zG / 100;

  yG = map(valueY, y_min, y_max, -100, 100);
  yG = yG / 100;

  xG = map(valueX, x_min, x_max, -100, 100);
  xG = xG / 100;

  alfa = atan( yG / sqrt( (xG * xG) + (zG * zG) ) );
  alfa = alfa * 180 / MPI; 
  //Serial.print("alpha: ");
  Serial.println(alfa);

  beta = atan( xG / sqrt( (yG * yG) + (zG * zG) ) );
  beta = -1 * beta * 180 / MPI; 
  //Serial.print("; betha: ");
  Serial.println(beta);
  
  //Serial.print("; X: ");
  //Serial.print(xG);
  //Serial.print("; Y: ");
  //Serial.print(yG);
  //Serial.print("; Z: ");
  //Serial.println(zG);
  delay(100);
}
