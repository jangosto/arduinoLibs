#ifndef RELE_H
#define RELE_H

#include "Arduino.h"

/**
    Rele Class
    It manages a rele
*/
class Rele
{
    public:
        /**
            Contructor
            @param connected rele pin number
        */
        Rele(int);

        /**
            Get pi number
        */
        int getPinNum();
        /**
            Get if rele status is "enabled"
        */
        boolean getEnabled();
        /**
            Enables rele
        */
        boolean enable();
        /**
            Disable rele
        */
        boolean disable();

    private:
        int pinNum;
        boolean enabled;
};

Rele::Rele(int pin)
{
    pinNum = pin;
    pinMode(pinNum, OUTPUT);
    enabled = false;
}

int Rele::getPinNum()
{
    return pinNum;
}

boolean Rele::getEnabled()
{
    return enabled;
}

boolean Rele::enable()
{
    digitalWrite(pinNum, LOW);
    enabled = true;

    return enabled;
}

boolean Rele::disable()
{
    digitalWrite(pinNum, HIGH);
    enabled = false;

    return enabled;
}


#endif
