// http://de.wikibooks.org/wiki/C%2B%2B-Programmierung:_Klassen

#ifndef DustSensor_H
#define DustSensor_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"  // for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif
//#include <Arduino.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"

#define samplingTime 280
#define deltaTime 40
#define sleepTime 9680

class DustSensor
{
  public:                             // öffentlich
    DustSensor();                     // der Default-Konstruktor
    DustSensor(int, int);             // weiterer Konstruktor mit Parameter
    //   PinClass(const LED& a);      // Copy-Konstruktor wird nicht benötigt
    ~DustSensor();                    // Class Destruktor

    float dustDensity();              // Staubdichte ausgeben
    float raw();                      // raw daten ausgeben
    float voltage();                  // Spannung berechnen

  private:                            // privat
    int _ledPin, _measurePin;

    float voMeasured = 0;
    float calcVoltage = 0;
    float calDensity = 0;

};

#endif // DustSensor_H

