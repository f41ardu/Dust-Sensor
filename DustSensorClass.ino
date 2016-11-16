/*
  Standalone Sketch to use with a Arduino Duemilanove, Uno, etc....  and a
  Sharp Optical Dust Sensor GP2Y1010AU0F
  06.11.2016 #f41_ardu 
*/
#include "DustSensor.h"

int measurePin = 0; //Connect dust sensor to Arduino A0 pin
int ledPower = 2;   //Connect 3 led driver pins of dust sensor to Arduino D2

DustSensor GP2Y1010AU0F(ledPower, measurePin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Raw Signal Value (0-1023): ");
  Serial.print(GP2Y1010AU0F.raw());
  Serial.print(" - Voltage: ");
  Serial.print(GP2Y1010AU0F.voltage());

  Serial.print(" - Dust Density: ");
  Serial.println(GP2Y1010AU0F.dustDensity()); // unit: mg/m3

  delay(1000);
}
