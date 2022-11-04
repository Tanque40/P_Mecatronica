#define VoltageRead A0
#define LED_LOW_BATTERY 13

#define MINIMUM_VOLTAGE 628  // for 6.4 Volts
#define MAXIMUM_VOLTAGE 843  // for 8.4 Volts

int voltage, battery;

int volmeter(int voltage) {
    return map(voltage, MINIMUM_VOLTAGE, MAXIMUM_VOLTAGE, 0, 100);
}

void LowBattery() {
    digitalWrite(LED_LOW_BATTERY, HIGH);
}

void LightFollower() {
    digitalWrite(LED_LOW_BATTERY, LOW);
    Serial.println("Light Follower");
}

void setup() {
    pinMode(LED_LOW_BATTERY, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    voltage = analogRead(VoltageRead);
    battery = volmeter(voltage);

    if (battery < 0) {
        LowBattery();
    } else {
        LightFollower();
    }

    delay(1000);
}
