#ifndef RELE_H
#define RELE_H

#include "Arduino.h"

class Rele
{
    public:
        Rele(int);

        int getPinNum();
        boolean getEnabled();
        boolean enable();
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