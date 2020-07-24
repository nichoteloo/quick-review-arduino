int LEDPin = 9;     // Declare LEDPin to be arduino Pin
int potPin = A0;    // Declare potPin to analog A0
int readValue;
int writeValue;

void setup() {
    Serial.begin(9600);
    pinMode(potPin, INPUT);
    pinMode(LEDPin, OUTPUT);
}

void loop() {
    readValue = analogRead(potPin);             // read voltage from potensiometer
    writeValue = (255./1023.) * readValue;      // calculate writeValue
    analogWrite(LEDPin, writeValue);            // send it to the LED
    Serial.print("You are writing the value of : ");
    Serial.println(writeValue);
}