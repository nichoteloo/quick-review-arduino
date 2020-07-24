// RGB LED

int redPin = 11;
int greenPin = 10;
int bluePin = 6;
int brightness = 75;    // Set brightness

void setup() {
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
    analogWrite(bluePin,brightness);    // set LED to green light
}

// u can set brightness both green and red LED as well.