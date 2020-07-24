// My Body My Rulse

String myName;
int age;
float height;

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Please enter your name ? ");
    while (Serial.available(!==0)) {}
    myName = Serial.readString();       // read string

    Serial.println("How old are you ? ");
    while (Serial.available(!==0)) {}
    age = Serial.parseInt();          // read age int

    Serial.println("How tall are you ? ");
    while (Serial.available(!==0)) {}
    height = Serial.parseFloat();          // read height float

    Serial.println(" ");

    // Output Statement
    Serial.print("Hello ");
    Serial.print(myName);
    Serial.print(", you are ");
    Serial.print(age);
    Serial.print(" years old.");
    Serial.print(" And you are ");
    Serial.print(height);
    Serial.print(" cm tall ");
    Serial.print(" ");
}