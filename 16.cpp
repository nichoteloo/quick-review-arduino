// Integrating LCD with Ultrasonic Sensor

#include <LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2);

int trigPin = 13;
int echoPin = 11;
float pingTime;
float targetDistance;
float speedOfSound = 776.5;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    LCD.begin(16,2);
    LCD.setCursor(0,0);
    LCD.print("Target Distance : ");
}

void loop() {

    digitalWrite(trigPin, LOW); // set trigger low
    delayMicroseconds(2000);    // pause to let settle
    digitalWrite(trigPin, HIGH);    // take trip pin HIGH
    delayMicroseconds(15);          // pause with trigger pin HIGH
    digitalWrite(trigPin, LOW);     // finish trigger pulse by bringing it low
    delayMicroseconds(10);          // briefly pause

    pingTime = pulseIn(echoPin, HIGH);      // microsecond
    pingTime = pingTime/1000000.;    // convert to second
    pingTime = pingTime/3600.;       // convert ping time to hour

    targetDistance = speedOfSound * pingTime;
    targetDistance = targetDistance/2;
    targetDistance = targetDistance*63360;  // convert to inch from miles

    LCD.setCursor(0,1);
    LCD.print("                ");
    LCD.setCursor(0,1);
    LCD.print(targetDistance);
    LCD.print(" inches");
    delay(250);     // avoid display jittery
}
