int redLEDPin = 9;
int yellowREDPin = 10;
int redOnTime = 250;
int redOffTime = 250;
int yellowOnTime = 250;
int yellowOffTime = 250;
int numRedBlink = 10;
int numYellowBlink = 10;

void setup() {
    pinMode (redLEDPin, OUTPUT);
    pinMode (yellowLEDPin, OUTPUT);
}

void loop() {

    for(i=1; i<=numRedBlink; i=i+1) {
        digitalWrite(redLEDPin, HIGH);
        delay(redOnTime);
        digitalWrite(redLEDPin, LOW);
        delay(redOffTime);
    }

    for(i=1; i<=numYellowBlink; i=i+1) {
    digitalWrite(yelloLEDPin, HIGH);
    delay(yelloOnTime);
    digitalWrite(yelloLEDPin, LOW);
    delay(yelloOffTime);
    }
    
}