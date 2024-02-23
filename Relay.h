#ifndef Relay_h
#define Relay_h

#include "Arduino.h"
#include "Ds18b20.h"

class Relay
{
   private :
        float dataTemp;           
        float consigne;
        float delta;
 
    public:
        Relay();               //Constructeur 
        void switchHot();         //fonction pour le relai de chauffage
        void switchCool();        //onction pour le relai du ventilateur
};
#endif
