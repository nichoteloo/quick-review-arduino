// Ultrasonic sensor

int trigPin = 13;
int echoPin = 11;
float pingTime; // travel time
float speedOfSound;
float targetDistance = 6;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW); // set trigger low
    delayMicroseconds(2000);    // pause to let settle
    digitalWrite(trigPin, HIGH);    // take trip pin HIGH
    delayMicroseconds(10);          // pause with trigger pin HIGH
    digitalWrite(trigPin, LOW);     // finish trigger pulse by bringing it low

    pingTime = pulseIn(echoPin, HIGH);  // input pulse travel time

    speedOfSound = 2*targetDistance/pingTime;       // gives us inches per ms

    Serial.print("Speed of sound is: ");
    Serial.print(speedOfSound);
    Serial.println("inches per ms.");
    delay(3000);

}