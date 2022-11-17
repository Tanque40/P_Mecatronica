#define MotXA_FORWARD 3
#define MotXA_BACKWARD 5

#define MotXB_FORWARD 4
#define MotXB_BACKWARD 6

#define SPEED_A_MOTOR 2
#define SPEED_B_MOTOR 7

#define SPEED_VALUE 1

/// @brief Control all the movement of the robot
/// @param LSignal values from -1 to 1, the movement of Left tyre
/// @param RSignal values from -1 to 1, the movement of Right tyre
void DriveRobot(float LSignal, float RSignal);

/// @brief Control the movement of the left tyre of the bot
/// @param LSignal values from -1 to 1, means the direction of the movement
/// @param Speed the speed of the movement
void DriveLeftRobot(float LSignal, float Speed);

/// @brief Control the movement of the right tyre of the bot
/// @param RSignal values from -1 to 1, means the direction of the movement
/// @param Speed the speed of the movement
void DriveRightRobot(float RSignal, float Speed);

int i = 0;

void setup() {
    pinMode(MotXA_FORWARD, OUTPUT);
    pinMode(MotXA_BACKWARD, OUTPUT);

    pinMode(MotXB_FORWARD, OUTPUT);
    pinMode(MotXB_BACKWARD, OUTPUT);

    pinMode(SPEED_A_MOTOR, OUTPUT);
    pinMode(SPEED_B_MOTOR, OUTPUT);
}

void loop() {
    if (i == 0) {
        DriveRobot(1, 1);
    } else if (i == 1) {
        DriveRobot(-1, -1);
    } else if (i == 2) {
        DriveRobot(1, -1);
    } else if (i == 3) {
        DriveRobot(-1, 1);
    } else if (i == 4) {
        DriveRobot(0, 0);
        i = -1;
    }
    i++;
    delay(2000);
}

void DriveRobot(float LSignal, float RSignal) {
    DriveLeftRobot(LSignal, SPEED_VALUE);
    DriveRightRobot(RSignal, SPEED_VALUE);
}

void DriveLeftRobot(float LSignal, float Speed) {
    float FinalSpeed = Speed * 255;
    if (LSignal == 1) {
        digitalWrite(MotXA_FORWARD, HIGH);
        digitalWrite(MotXA_BACKWARD, LOW);
        analogWrite(SPEED_A_MOTOR, FinalSpeed);
    } else if (LSignal == -1) {
        digitalWrite(MotXA_FORWARD, LOW);
        digitalWrite(MotXA_BACKWARD, HIGH);
        analogWrite(SPEED_A_MOTOR, FinalSpeed);
    } else {
        FinalSpeed = 0;
        digitalWrite(MotXA_FORWARD, HIGH);
        digitalWrite(MotXA_BACKWARD, LOW);
        analogWrite(SPEED_A_MOTOR, FinalSpeed);
    }
}

void DriveRightRobot(float RSignal, float Speed) {
    int FinalSpeed = Speed * 255;
    if (RSignal == 1) {
        digitalWrite(MotXB_FORWARD, HIGH);
        digitalWrite(MotXB_BACKWARD, LOW);
        analogWrite(SPEED_B_MOTOR, FinalSpeed);
    } else if (RSignal == -1) {
        digitalWrite(MotXB_FORWARD, LOW);
        digitalWrite(MotXB_BACKWARD, HIGH);
        analogWrite(SPEED_B_MOTOR, FinalSpeed);
    } else {
        FinalSpeed = 0;
        digitalWrite(MotXB_FORWARD, HIGH);
        digitalWrite(MotXB_BACKWARD, LOW);
        analogWrite(SPEED_B_MOTOR, FinalSpeed);
    }
}
