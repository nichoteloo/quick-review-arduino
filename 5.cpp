// Analog

int redLEDPin = 9;
int yellowREDPin = 10;
int redOnTime = 250;
int redOffTime = 250;
int yellowOnTime = 250;
int yellowOffTime = 250;
int numYellowBlink = 5;
int numRedBlink = 5;
int writeValueRed;
int writeValueYellow;
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
    Serial.println("What do you want to write number in RED LED ?");    // prompt user
    while(Serial.available()==0){ }      // wait for input
    writeValueRed = Serial.parseInt();   // read user input

    // Setup once in begining of program
    Serial.println("What do you want to write number in Yellow LED ?");
    while(Serial.available()==0){ }
    writeValueYellow = Serial.parseInt();
}

void loop() {

    Serial.println(redMessage);  // title
    int i=1;
    while(i<=numRedBlink) {
        Serial.print("   You are on Blink # : ");
        Serial.println(i);  // print out in the monitor
        analogWrite(redLEDPin, writeValueRed);      // apply analog voltage
        delay(redOnTime);
        analogWrite(redLEDPin, 0);
        delay(redOffTime);
        i++;
    }

    Serial.println(" ");   // enter section

    Serial.println(yellowMessage);
    int i=1;
    while(i<=numYellowBlink) {
        Serial.print("   You are on Blink # : ");
        Serial.println(i);
        analogWrite(yelloLEDPin, writeValueYellow);    // apply analog voltage
        delay(yelloOnTime);
        analogWrite(yelloLEDPin, 0);
        delay(yelloOffTime);
        i++;
    }  
}