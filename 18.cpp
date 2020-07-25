// GPS Tracker
// GPS Adafruit Library (install and put in Arduino Libraries folder)

#include <Adafruit_GPS.h>       // Install adafruit library
#include <SoftwareSerial.h>     // set serial port by load the software serial library

SoftwareSerial mySerial(3,2);   // on pin 3 and 2, initialize software serial port
Adafruit_GPS GPS(&mySerial); //Create GPS object

String NMEA1;  //We will use this variable to hold our first NMEA sentence
String NMEA2;  //We will use this variable to hold our second NMEA sentence
char c;       //Used to read the characters spewing from the GPS module

void setup() {
    Serial.begin(115200);   // Turn on the Serial Monitor
    GPS.begin(9600);        // Turn GPS on baud rate 9600
    GPS.sendCommand("$PGCMD,33,0*6D");  // send off GPS Antenna Update
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);   //Tell GPS we want only $GPRMC and $GPGGA NMEA sentences
    GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);  // 1 Hz update rate
    delay(1000);  //Pause
}

void loop() {
    readGPS();  //This is a function we define below which reads two NMEA sentences from GPS
}

void readGPS() {
    clearGPS();

    while(!GPS.newNMEAreceived()) { //Keep reading characters in this loop until a good NMEA sentence is received
        c = GPS.read(); //read a character from the GPS
    }
    GPS.parse(GPS.lastNAME());  //Once you get a good NMEA, parse it

    NMEA1=GPS.lastNMEA();      //Once parsed, save NMEA sentence into NMEA1

    while(!GPS.newNMEAreceived()) {  //Go out and get the second NMEA sentence, should be different type than the first one read above.
        c=GPS.read();
    }
    GPS.parse(GPS.lastNMEA());

    NMEA2=GPS.lastNMEA();

    Serial.println(NMEA1);
    Serial.println(NMEA2);
    Serial.println("");
    
}

void clearGPS() {  //Since between GPS reads, we still have data streaming in, we need to clear the old data by reading a few sentences, and discarding these
    while(!GPS.newNMEAreceived()) {
        c = GPS.read();
    }
    GPS.parse(GPS.lastNMEA());

    while(!GPS.newNMEAreceived()) {
        c = GPS.read();
    }
    GPS.parse(GPS.lastNMEA());
}