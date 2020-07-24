int redLEDPin = 9;
int yellowREDPin = 10;
int redOnTime = 250;
int redOffTime = 250;
int yellowOnTime = 250;
int yellowOffTime = 250;
int numRedBlink = 10;
int numYellowBlink = 10;
String redMessage = "The RED LED is Blinking";
String yellowMessage = "The Yellow LED is Blinking";

void setup() {
    Serial.begin(9600); // setting up port initialization, baud at the port must be 9600

    // local string
    String var1 = "Welcome To";
    String var2 = "My Program";
    String var3;
    var3 = var2 + var1;
    Serial.println(var3);

    pinMode (redLEDPin, OUTPUT);
    pinMode (yellowLEDPin, OUTPUT);
}

void loop() {

    Serial.println(redMessage);  // title
    for(int i=1; i<=numRedBlink; i=i+1) {
        Serial.print("   You are on Blink # : ");
        Serial.println(i);  // print out in the monitor
        digitalWrite(redLEDPin, HIGH);
        delay(redOnTime);
        digitalWrite(redLEDPin, LOW);
        delay(redOffTime);
    }

    Serial.println(" ");   // enter section

    Serial.println(yellowMessage);
    for(int i=1; i<=numYellowBlink; i=i+1) {
        Serial.print("   You are on Blink # : ");
        Serial.println(i);
        digitalWrite(yelloLEDPin, HIGH);
        delay(yelloOnTime);
        digitalWrite(yelloLEDPin, LOW);
        delay(yelloOffTime);
    }
    
}