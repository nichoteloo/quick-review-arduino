// Potensiometer

int potPen = A0;       // Assign potPen to A0
int readValue;          // declare variable
float Voltage;

void setup() {
    pinMode(potPen, INPUT);     // set input
    Serial.begin(9600);     // start serial input
}

void loop() {
    readValue = analogRead(potPen);     // read potPen and put value in readValue
    Voltage = (5./1023.)*readValue;
    Serial.println(Voltage);      // print result to serial monitor
    delay(250);         // Delay 250 milisekon
}