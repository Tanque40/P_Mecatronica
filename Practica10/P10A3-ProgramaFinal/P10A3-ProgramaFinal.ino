#include <LiquidCrystal_I2C.h>  //Incluimos la libreria para comunicarnos por I2C con el LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define MOTOR_A_FORWARD 4      // Pin de control del motor A
#define MOTOR_A_BACKWARD 3     // Pin de control del motor A
#define MOTOR_B_FORWARD 6      // Pin de control del motor b
#define MOTOR_A_BACKWARD 5     // Pin de control del motor b
#define ENABLE_1 2             // Enable motor 1
#define ENABLE_2 7             // Enable motor 2
#define VOLTAGE A1             // medidor de VOLTAGE
#define FOTORESISTOR_RIGHT A2  // primer fotoresistor
#define FOTORESISTOR_LEFT A3   // segundo fotoresistor
#define FOTORESISTOR_BACK A4   // tercer fotoresistor
#define FOTORESISTOR_RC A5     // cuarto fotoresistor
#define TRIGGER 53             // pin de TRIGGERger
#define ECHO 51                // pin de ECHO
#define SHARP_FIRST A8         // primer sensor sharp
#define SHARP_SECOND A9        // segundo sensor sharp

float VOLTAGEI, VOLTAGEA, VOLTAGERC, VOLTAGED, vSHARP_FIRST, vSHARP_SECOND, VOLTAGESistema, diferencia_luz, US_Sensor;  // definimos las variables que guardaran lo obtenido por los pines
int battery;
boolean obs;

void setup() {
    // put your setup code here, to run once:
    // Definimos la comunicaciòn serial e inicializamos todos nuestros puertos como salidas para el motor y el de ECHO del ultrasonico como entrada. La pantalla lcd igual se inicia
    Serial.begin(9600);
    pinMode(MOTOR_A_FORWARD, OUTPUT);
    pinMode(MOTOR_A_BACKWARD, OUTPUT);
    pinMode(MOTOR_B_FORWARD, OUTPUT);
    pinMode(MOTOR_A_BACKWARD, OUTPUT);
    pinMode(ENABLE_1, OUTPUT);
    pinMode(ENABLE_2, OUTPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);

    lcd.init();
}

void loop() {
    // Hacemos uso de las funciones definidas que sensan el medio y imprimen los datos

    voltageSensor();
    distanceSensor();
    followlight();
    lcd_print();
    driveRobot(1, 1);  // Movemos el robot 1 segundo hacia adelante y lo paramos
    delay(1000);
    driveRobot(0, 0);
    delay(1000);
}

// Mètodo que genera los movimientos por rueda dependiendo de las variables de entrada, mandando señales digitales al puente h
void driveRobot(float LSignal, float RSignal) {
    if (LSignal < 0 && RSignal < 0) {
        digitalWrite(MOTOR_A_BACKWARD, HIGH);
        digitalWrite(MOTOR_B_FORWARD, LOW);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, HIGH);
        digitalWrite(MOTOR_A_FORWARD, LOW);
        digitalWrite(ENABLE_1, 85);
    }
    if (LSignal < 0 && RSignal == 0) {
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_B_FORWARD, LOW);
        digitalWrite(ENABLE_2, 0);
        digitalWrite(MOTOR_A_BACKWARD, HIGH);
        digitalWrite(MOTOR_A_FORWARD, LOW);
        digitalWrite(ENABLE_1, 85);
    }
    if (LSignal < 0 && RSignal > 0) {
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_B_FORWARD, HIGH);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, HIGH);
        digitalWrite(MOTOR_A_FORWARD, LOW);
        digitalWrite(ENABLE_1, 85);
    }
    if (LSignal == 0 && RSignal == 0) {
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_B_FORWARD, LOW);
        digitalWrite(ENABLE_2, 0);
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_A_FORWARD, LOW);
        digitalWrite(ENABLE_1, 0);
    }
    if (LSignal == 0 && RSignal < 0) {
        digitalWrite(MOTOR_A_BACKWARD, HIGH);
        digitalWrite(MOTOR_B_FORWARD, LOW);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_A_FORWARD, LOW);
        digitalWrite(ENABLE_1, 0);
    }
    if (LSignal == 0 && RSignal > 0) {
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_B_FORWARD, HIGH);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_A_FORWARD, LOW);
        digitalWrite(ENABLE_1, 85);
    }
    if (LSignal > 0 && RSignal > 0) {
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_B_FORWARD, HIGH);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_A_FORWARD, HIGH);
        digitalWrite(ENABLE_1, 85);
    }
    if (LSignal > 0 && RSignal == 0) {
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_B_FORWARD, LOW);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_A_FORWARD, HIGH);
        digitalWrite(ENABLE_1, 85);
    }
    if (LSignal > 0 && RSignal < 0) {
        digitalWrite(MOTOR_A_BACKWARD, HIGH);
        digitalWrite(MOTOR_B_FORWARD, LOW);
        digitalWrite(ENABLE_2, 40);
        digitalWrite(MOTOR_A_BACKWARD, LOW);
        digitalWrite(MOTOR_A_FORWARD, HIGH);
        digitalWrite(ENABLE_1, 85);
    }
}
void voltageSensor() {
    VOLTAGESistema = analogRead(VOLTAGE);  // leemos el VOLTAGE de alimentación y si es menor a 650 bits ponemos battery = 0 para alertar de bajo voltage
    if (VOLTAGESistema > 650) {
        battery = 1;
    } else {
        battery = 0;
    }
}
void lightSensor() {
    VOLTAGED = analogRead(FOTORESISTOR_RIGHT);  // Sensamos la luz del medio con cuatro fotoresistores y usamos las de los lados para calcular la diferencia
    VOLTAGEI = analogRead(FOTORESISTOR_LEFT);
    VOLTAGEA = analogRead(FOTORESISTOR_BACK);
    diferencia_luz = VOLTAGED - VOLTAGEI;
    lcd.setCursor(0, 0);
    lcd.print("L: ");
    lcd.print(VOLTAGEI);
    lcd.setCursor(12, 0);
    lcd.print("D: ");  // En el lcd imprimimos los datos para tener una interfaz del estado del robot
    lcd.print(VOLTAGED);
    lcd.setCursor(0, 1);
    lcd.print("D: ");
    lcd.print(diferencia_luz);
    lcd.setCursor(8, 1);
    lcd.print("A: ");
    lcd.print(VOLTAGEA);
}
bool distanceSensor() {
    vSHARP_FIRST = analogRead(SHARP_FIRST);
    vSHARP_SECOND = analogRead(SHARP_SECOND);  // Sensamos los objetos que estan proximos a la locomocion con tres sensores (Dos Sharp y uno US)

    vSHARP_FIRST = 1990 * (pow(vSHARP_FIRST, -0.921));  // Funcion de lectura del sharp
    vSHARP_SECOND = 1990 * (pow(vSHARP_SECOND, -0.921));
    // Distancia con  ultrasònico
    digitalWrite(TRIGGER, LOW);  // Hacemos el envío y recepción del pulso ultrasonico
    delayMicroseconds(2);

    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);

    US_Sensor = pulseIn(ECHO, HIGH);  // Calculamos la distancia que registro a partir de las lecturas
    US_Sensor = US_Sensor * 0.0343 / 2;
    if (US_Sensor < 8) {
        obs = true;
    } else {
        obs = false;
    }
}

void followlight() {  // En esta función seguiremos la luz haciendo llamar la función driverobot

    if (diferencia_luz < -300) {
        driveRobot(1, -1);  // corregimos por unos segundos hacia la derecha
        delay(500);
        driveRobot(1, 1);
    } else if (diferencia_luz > 300) {
        driveRobot(-1, 1);  // Corregimos unos milisegundos a la derecha
        delay(200);
        driveRobot(1, 1);

    } else {
        driveRobot(1, 1);  // estara en el umbral de luz para indicar que esta delante
    }
}
void lcd_print() {
    lcd.setCursor(0, 0);  // Imprimimos la diferencia de luz entre el lado derECHO y izquierdo y tambien imprimimos el valor de battery
    lcd.print("light_dif: ");
    lcd.print(diferencia_luz);
    lcd.setCursor(0, 1);
    lcd.print("battery: ");
    lcd.print(battery);
}
