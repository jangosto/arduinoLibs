# include "TimedDevice.h"

TimedDevice(int pin, unsigned long newOnTime, unsigned long newOffTime)
{
    pinNum = pin;
    onTime = newOnTime;
    offTime = newOffTime;
    enabled = false;
    currentTime = 0;

    Rele rele = new Rele(pin);
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

boolean TimedDevice::updateStatus()
{
    unsigned long time;

    time = increaseCurrentTime();
    if (time >= onTime && enabled == true) {
        rele.disable();
        resetCurrentTime();
    } else if (time >= offTime && enabled == false) {
        rele.enable();
        resetCurrentTime();
    }

    return enabled;
}

unsigned long TimedDevice::increaseCurrentTime()
{
    currentTime++;
    return currentTime;
}

void TimedDevice::resetCurrentTime()
{
    currentTime = 0;
}
