// Interact with LCD

#include <LiquidCrystal.h>  // load the liquid crystal library
LiquidCrystal LCD(10,9,5,4,3,2);    // create object, with followed pins respectively
int myCounter=0;    // declare variable myCounter;

void setup() {
    LCD.begin(16,2);    // tell arduino LED has 16 columns and 2 rows
    LCD.setCursor(0,0); // set LED cursor to upper left of display
    LCD.print("My Timer : ");
}

void loop() {
    for (myCounter=1; myCounter <= 10; myCounter+1) {
        
        LCD.setCursor(0,1);
        LCD.print("                ");  // clear the line, avoid double s appears.

        LCD.setCursor(0,1);
        LCD.print(myCounter);
        LCD.print(" Seconds");
        delay(1000);
    }
    
    for (myCounter=10; myCounter >= 1; myCounter-1) {

        LCD.setCursor(0,1);
        LCD.print("                ");  // clear the line, avoid double s appears.

        LCD.setCursor(0,1);
        LCD.print(myCounter);
        LCD.print(" Seconds");
        delay(1000);
    }
}