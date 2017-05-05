# include "TimedDevice.h"

TimedDevice(int pin, unsigned long onTime, unsigned long offTime)
{
    setPinNum(pin);
    setOnTime(onTime);
    setOffTime(offTime);
    setEnabled(false);

    rele = new Rele(pin);
    setRele(rele);
}

int TimedDevice::getPinNum()
{
    return pinNum;
}

unsigned long TimedDevice::getOffTime()
{
    return offTime;
}

unsigned long TimedDevice::getOnTime()
{
    return onTime;
}

boolean TimedDevice::getEnabled()
{
    return enabled;
}

Rele TimedDevice::getRele()
{
    return rele;
}

int TimedDevice::setPinNum(int pin)
{
    pinNum = pin;
    return pinNum;
}

unsigned long TimedDevice::setOffTime(unsigned long time)
{
    offTime = time;
    return offTime;
}

unsigned long TimedDevice::setOnTime(unsigned long time)
{
    onTime = time;
    return onTime;
}

boolean TimedDevice::setEnabled(boolean en)
{
    enabled = en;
    return enabled;
}

Rele TimedDevice::setRele(Rele re)
{
    rele = re;
    return rele;
}
