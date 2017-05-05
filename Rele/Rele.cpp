#include "Rele.h"

Rele::Rele(int pin)
{
    setPinNum(pin);
    setEnabled(false);
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
    digitalWrite(piNum, LOW);
    setEnabled(true);

    return enabled;
}

boolean Rele::disable()
{
    digitalWrite(pinNum, HIGH);
    setEnabled(false);

    return enabled;
}

boolean Rele::setEnabled(boolean en)
{
    enabled = en;
    return enabled;
}

int Rele::setPinNum(int pin)
{
    pinNum = pin;
    return pinNum;
}
