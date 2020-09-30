#include <SPI.h>
#include <SD.h>

int speedMotor = 0;

File data;

void setup() {
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
  }
  
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0){
    // read data from atmega
    speedMotor = Serial.parseInt();

    data = SD.open("data.csv", FILE_WRITE);
    if (data){
      data.println(speedMotor);
    } else {
      Serial.println("error opening data.csv");
    }
  }
}
