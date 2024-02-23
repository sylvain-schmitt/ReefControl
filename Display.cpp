#include <Arduino.h>
#include "Display.h"
#include "Ds18b20.h"

byte TEMP_PIN = 2; //sonde de température definie sur pin 2
Ds18b20 temp(TEMP_PIN);
Display::Display(){};

void Display::SetTempBac()
{
  float dataTemp = temp.GetTempBac();
  Serial.print("t0.txt=\"");
  Serial.print(dataTemp, 1);
  Serial.print(" "); 
  Serial.write(0xB0); 
  Serial.print("C\"");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  delay(1000);
}