// Servo and Potensiometer

#include <Servo.h>
int pos = 0;
int servoPin = 9;   // Tell arduino that servo is hooked to pin 9
int potReading;
int potPin = A0;    // connect potensio to A0
int servoDelay = 25;

Servo myPointer;    // create a servo object called myPointer

void setup() {
    Serial.begin(9600);
    pinMode(servoPin, OUTPUt);
    myPointer.attach(servoPin);
}

void loop() {
        // debug servo jitter
    // Serial.prinln("Position of the servo ? ");
    // while(Serial.available()==0) {}
    // pos = Serial.parseInt();
    // myPointer.write(pos);

        // example: min 15 deg max 175 deg
    // for (pos = 15; pos<=175; pos=pos+1) {
    //     myPointer.write(pos);
    // }
    // for (pos = 175; pos>=15; pos=pos-1) {
    //     myPointer.write(pos);
    // }

        // Control with potensio
    potReading = analogRead(potPin);
    pos = (155./1023.)*potReading + 15;
    myPointer.write(pos);
}