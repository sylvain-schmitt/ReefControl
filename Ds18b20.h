#ifndef Ds18b20_h
#define Ds18b20_h

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class Ds18b20
{
  public:
    Ds18b20(uint8_t);
    float GetTempBac();
    float GetTempTds();
    void begin();
  private:
    uint8_t _pin;
    OneWire _wire;
    DallasTemperature _sensors;
};
#endif