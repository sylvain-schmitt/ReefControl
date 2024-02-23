#include <Arduino.h>
#include "Relay.h"
#include "Ds18b20.h"

byte TEMP_PIN_RELAY = 2; //sonde de température definie sur pin 2
Ds18b20 temp_relay(TEMP_PIN_RELAY);

float consigne;
float delta;
float dataTemp;
const int RELAY_HOT = 3;
const int RELAY_COOL = 4;

Relay::Relay()
{
  pinMode(RELAY_HOT, OUTPUT);
  pinMode(RELAY_COOL, OUTPUT);
}

void Relay::switchHot()
{
  float dataTemp = temp_relay.GetTempBac();
  float consigne = 25;
  float delta = 0.5;
  if(dataTemp < consigne - delta){
    digitalWrite(RELAY_HOT, HIGH);
    Serial.print("t2.txt=\"ON\"");
    Serial.write(0xFF);               
    Serial.write(0xFF);
    Serial.write(0xFF);
    delay( 100 );            
    
  }
  if(dataTemp > consigne) {
    digitalWrite(RELAY_HOT, LOW);
    Serial.print("t2.txt=\"Off\"");    
    Serial.write(0xFF);               
    Serial.write(0xFF);
    Serial.write(0xFF);
    delay( 100 );            
  }
}

void Relay::switchCool()
{
  float dataTemp = temp_relay.GetTempBac();
  float consigne = 25;
  float delta = 0.5;
  if(dataTemp > consigne + delta){
    digitalWrite(RELAY_COOL, HIGH);
    Serial.print("t3.txt=\"ON\"");    
    Serial.write(0xFF);               
    Serial.write(0xFF);
    Serial.write(0xFF);
    delay( 100 );            
  }
  if(dataTemp < consigne) {
    digitalWrite(RELAY_COOL, LOW);
    Serial.print("t3.txt=\"Off\"");   
    Serial.write(0xFF);               
    Serial.write(0xFF);
    Serial.write(0xFF);
    delay( 100 );            
  }
}