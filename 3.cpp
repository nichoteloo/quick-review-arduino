int redLEDPin = 9;
int yellowREDPin = 10;
int redOnTime = 250;
int redOffTime = 250;
int yellowOnTime = 250;
int yellowOffTime = 250;
int numRedBlink;
int numYellowBlink;
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

    // Setup once in begining of program
    Serial.println("How many times do you want RED LED to blink ?");    // prompt user
    while(Serial.available()==0){ }      // wait for input
    numRedBlink = Serial.parseInt();   // read user input

    // Setup once in begining of program
    Serial.println("How many times do you want Yellow LED to blink ?");
    while(Serial.available()==0){ }
    numYellowBlink = Serial.parseInt();

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