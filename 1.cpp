// Simple case, checking input on Arduino LED

int LEDPin=13;
int waitTimeOn=900;
int waitTimeOff=100;

void setup() {
    pinMode (LEDPin, OUTPUT);
}

void loop() {
    digitalWrite (LEDPin, HIGH);
    delay(waitTimeOn);
    digitalWrite (LEDPin, LOW);
    delay(waitTimeOff);
}