// Data logging to SD Card Reader

#include <SD.h> // load SD library
#include <SPI.h> // load SPI communication library

#include "Wire.h"   //  import library for talking over I2C
#include "Adafruit_BMP085.h"    // import pressure and temp sensor library
Adafruit_BMP085 mySensor; // create mySensor as an object

float tempC;
float tempF;
float pressure;

int chipSelect = 4; //chipSelect pin for the SD card Reader
File mySensorData;  //Data object you will write your sensor data

void setup() {
    Serial.begin(9600);
    mySensor.begin();   //initialize pressure and temp sensor mySensor

    pinMode(10, OUTPUT);    // Must declare 10 an output and reserve it
    SD.begin(chipSelect);    // Initialize the SD card reader
}

void loop() {
    tempC = mySensor.readTemperature();     // Read temperature (default C)
    tempF = tempC*1.8 + 32.;    // convert from C to F
    pressure = mySensor.readPressure();     // Read pressure

    mySensorData = SD.open("PTData.txt", FILE_WRITE);   // open PTData.txt on the SD Card as a file to write to

    if (mySensorData) {
        Serial.print("The Temp is: "); //Print Your results
        Serial.print(tempF);
        Serial.println(" degrees F");
        Serial.print("The Pressure is: ");
        Serial.print(pressure);
        Serial.println(" Pa.");
        Serial.println("");
        delay(250); //Pause between readings.
    
        // to ease readability in excel file
        mySensorData.print(tempF);   // write tempF to the SD Card                     
        mySensorData.print(",");     // write comma
        mySensorData.println(pressure);    // write pressure data and go to next line
        mySensorData.close();   // close the file
    }
}