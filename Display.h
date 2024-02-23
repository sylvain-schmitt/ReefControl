#ifndef Display_h
#define Display_h

#include <Arduino.h>
#include "Ds18b20.h"

class Display
{
  public:
    Display();
    void SetTempBac();
    void SetTempTds(); 
};
#endif
