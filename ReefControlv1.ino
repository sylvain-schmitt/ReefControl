#include "Ds18b20.h"
#include "Display.h"
#include "Relay.h"


Display display;
Relay relay;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  //float temp_bac = temp.GetTempBac(); //recuperation de la température
  //Serial.print("Récuperation de la température du bac");
  //Serial.println(temp_bac,1 );
  //delay( 1000 );
  display.SetTempBac();
  relay.switchHot();
  relay.switchCool();

}
