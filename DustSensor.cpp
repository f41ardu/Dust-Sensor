#include "DustSensor.h"

DustSensor::DustSensor():
  _ledPin(0), _measurePin(0)
{
  // Default Constructor
}

DustSensor::DustSensor(int ledPin, int measurePin):
  _ledPin(ledPin), _measurePin(measurePin)
// SensorPin initialisieren
{
  pinMode(_ledPin, OUTPUT);
}

// Destructor
DustSensor::~DustSensor()
// Destructore 
{

}
float DustSensor::raw()
{
// Sensor auslesen 
  digitalWrite(_ledPin, LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(_measurePin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(_ledPin, HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
  return voMeasured;
}

float DustSensor::voltage()
{
  calcVoltage = voMeasured * (5.0 / 1024.0);
  return calcVoltage;
}

float DustSensor::dustDensity()
{
  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  return 0.17 * calcVoltage - 0.1;
}


