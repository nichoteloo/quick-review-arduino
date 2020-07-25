// Servo and Ultrasonic Sensor


#include <Servo.h>

int trigPin = 13;
int echoPin = 11;
int servoControlPin = 6;

float pingTime;
float targetDistance;
float speedOfSound = 776.05;    // miles per hour
float servoAngle;

Servo myPointer;

void setup() {
    Serial.begin(9600);
    pinMode(servoControlPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    myPointer.attach(servoControlPin);  // Pin where servo is connected
}

void loop() {

    digitalWrite(trigPin, LOW); // set trigger low
    delayMicroseconds(2000);    // pause to let settle
    digitalWrite(trigPin, HIGH);    // take trip pin HIGH
    delayMicroseconds(10);          // pause with trigger pin HIGH
    digitalWrite(trigPin, LOW);     // finish trigger pulse by bringing it low

    pingTime = pulseIn(echoPin, HIGH);      // microsecond
    pingTime = pingTime/1000000.;    // convert to second
    pingTime = pingTime/3600.;       // convert ping time to hour

    targetDistance = speedOfSound * pingTime;
    targetDistance = targetDistance/2;
    targetDistance = targetDistance*63360;  // convert to inch from miles

    Serial.print("The distance to the target is : ");
    Serial.print(targetDistance);
    Serial.println(" inches");

    servoAngle = (106./7.) * targetDistance + 37;
    myPointer.write(servoAngle);

    delay(1000);
}