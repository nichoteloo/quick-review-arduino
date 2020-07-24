// Simple case, checking input on RED LED Breadboard

int redLED = 9;
int onTime = 100;
int offTime = 900;

void setup() {
    pinMode (redLED, OUTPUT);
}

void loop() {
    digitalWrite (redLED, HIGH);
    delay(onTime);
    digitalWrite (redLED, LOW);
    delay(offTime);
}