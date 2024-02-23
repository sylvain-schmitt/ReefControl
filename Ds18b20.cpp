#include <OneWire.h>
#include <DallasTemperature.h>
#include "Ds18b20.h"

//byte TEMP_PIN = 2; //sonde de température definie sur pin 2
//Ds18b20 temp(TEMP_PIN);

Ds18b20::Ds18b20(uint8_t pin):_pin(pin), _wire(pin), _sensors(&_wire){
  _sensors.begin();
} 

float Ds18b20::GetTempBac()
    {
    _sensors.setResolution(12);
    _sensors.requestTemperatures();
    float tempBac = _sensors.getTempCByIndex(0);
    return tempBac;
    } 