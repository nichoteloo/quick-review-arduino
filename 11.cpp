// ColorSensor and RGB LED

int redPin = 11;
int greenPin = 10;
int bluePin = 6;

int S2 = 7;
int S3 = 6;
int outPin = 4;   // input Arduino

int rColorStrength;
int gColorStrength;
int bColorStrength;

unsigned int pulseWidth;

void setup() {
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(outPin, INPUT);
}

void loop() {

    // Read red component
    // S2 S3 set LOW;
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    pulseWidth = pulseIn(outPin, LOW);
    rColorStrength = pulseWidth/400. - 1;       // 400 ms period
    rColorStrength = (255-rColorStrength);

    // Read green component
    // S2 S3 set HIGH;
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    pulseWidth = pulseIn(outPin, LOW);
    gColorStrength = pulseWidth/400. - 1;
    gColorStrength = (255-gColorStrength);

    // Read blue component
    // S2 S3 set LOW and HIGH respectively;
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    pulseWidth = pulseIn(outPin, LOW);
    bColorStrength = pulseWidth/400. - 1;
    bColorStrength = (255-bColorStrength);


    if (rColorStrength > gColorStrength && gColorStrength > bColorStrength) {
        rColorStrength = 255;
        gColorStrength = gColorStrength/2;
        bColorStrength = 0;
    }

    if (gColorStrength > rColorStrength && rColorStrength > bColorStrength) {
        gColorStrength = 255;
        rColorStrength = bColorStrength/2;
        bColorStrength = 0;
    }

    if (gColorStrength > bColorStrength && bColorStrength > rColorStrength) {
        gColorStrength = 255;
        bColorStrength = bColorStrength/2;
        rColorStrength = 0;
    }

    if (bColorStrength > rColorStrength && rColorStrength > gColorStrength) {
        bColorStrength = 255;
        rColorStrength = bColorStrength/2;
        gColorStrength = 0;
    }

    if (bColorStrength > gColorStrength && gColorStrength > rColorStrength) {
        bColorStrength = 255;
        gColorStrength = bColorStrength/2;
        rColorStrength = 0;
    }

    // thick it
    bColorStrength = bColorStrength * .5;
    gColorStrength = bColorStrength * .75;

    Serial.print(rColorStrength);
    Serial.print(" , ");
    Serial.print(gColorStrength);
    Serial.print(" , ");
    Serial.print(bColorStrength);
    Serial.print("");

    analogWrite(redPin, rColorStrength);
    analogWrite(greenPin, gColorStrength);
    analogWrite(bluePin, bColorStrength);

    delay(250);

}