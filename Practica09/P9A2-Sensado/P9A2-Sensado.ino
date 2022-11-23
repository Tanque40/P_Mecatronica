#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <math.h>

#include "DHT.h"

#define VoltageRead A1

#define MINIMUM_VOLTAGE 628  // for 6.4 Volts
#define MAXIMUM_VOLTAGE 843  // for 8.4 Volts

#define LEFT_LDR A2
#define RIGHT_LDR A3
#define BACK_LDR A4

#define LEFT_SHARP A8
#define RIGHT_SHARP A9
#define ULTRASONIC_ECHO 53
#define ULTRASONIC_TRIGGER 51

#define DHTPIN 21
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

/// @brief Read the ADC value from voltage divisor
/// @details Read the ADC value from voltage divisor, save the value
///          in \var voltage, also modify the \var battery with 0 value
///          if no battery or 1 if there is battery remain
void voltageSensor();
/// @brief Reads the response fron voltage divisor and map
///        MINIMUM_VOLTAGE and MAXIMUM_VOLTAGE from 0 to 100
/// @param voltage the value readed on the voltage divisor
/// @return the mapped value of voltage
int volmeter(int voltage);
int battery = 1;
int voltage;

/// @brief Reads each LDR and save values in variables L_LDR, R_LDR, B_LDR
///        save on light_dif the difference between L_LDR and R_LDR
void lightSensor();
int L_LDR, R_LDR, B_LDR, light_dif;

/// @brief Reads value from LEFT_SHARP, RIGHT_SHARP and ULTRASONIC_SENSOR
///        and save the value in centimeters in US_Sensor, L_Sharp and R_Sharp
void distanceSensor();
int US_Sensor;
double L_Sharp, R_Sharp;
/// @brief Follow the (duration * 0.0343 / 2) formula to calculate the distance
/// @param duration the duration to recive the echo
/// @return The distance in centimeters
int UltraSonicSensorDistance(long duration);
/// @brief Follow the (7391.9 * pow(readValue, -1.219)) formula to calculate distance
/// @param readValue Value that returns the sharp sensor
/// @return The distance in centimeters
double SharpDistance(int readValue);

/// @brief Read the temperature and saves in varibale
void temperature_sensor();
float temperature;

/// @brief Print in LCD the light_dif value
///        and show if we have battery
void LCD_print();

void setup() {
    pinMode(ULTRASONIC_ECHO, INPUT);
    pinMode(ULTRASONIC_TRIGGER, OUTPUT);

    lcd.init();
    lcd.backlight();
}

void loop() {
    voltageSensor();
    lightSensor();
    distanceSensor();
    LCD_print();
    delay(2000);
}

void voltageSensor() {
    voltage = analogRead(VoltageRead);
    battery = volmeter(voltage);

    if (battery < 0) {
        battery = 0;
    } else {
        battery = 1;
    }
}

int volmeter(int voltage) {
    return map(voltage, MINIMUM_VOLTAGE, MAXIMUM_VOLTAGE, 0, 100);
}

void lightSensor() {
    L_LDR = analogRead(LEFT_LDR);
    R_LDR = analogRead(RIGHT_LDR);
    B_LDR = analogRead(BACK_LDR);

    light_dif = R_LDR - L_LDR;
}

void distanceSensor() {
    int readValueSharp;
    long duration;

    readValueSharp = analogRead(LEFT_SHARP);
    L_Sharp = SharpDistance(readValueSharp);

    readValueSharp = analogRead(RIGHT_SHARP);
    R_Sharp = SharpDistance(readValueSharp);

    digitalWrite(ULTRASONIC_TRIGGER, LOW);
    delayMicroseconds(2);

    digitalWrite(ULTRASONIC_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIGGER, LOW);

    duration = pulseIn(ULTRASONIC_ECHO, HIGH);
    US_Sensor = UltraSonicSensorDistance(duration);
}

int UltraSonicSensorDistance(long duration) {
    int distance;

    distance = duration * 0.0343 / 2;

    return distance;
}

double SharpDistance(int readValue) {
    double distance;

    distance = 7391.9 * pow(readValue, -1.219);

    return distance;
}

void temperature_sensor() {
    temperature = dht.readTemperature();
}

void LCD_print() {
    lightSensor();

    lcd.setCursor(0, 0);
    lcd.print(light_dif);

    lcd.setCursor(0, 1);
    if (battery) {
        lcd.print("Light Follower");
    } else {
        lcd.print("No battery");
    }
}
