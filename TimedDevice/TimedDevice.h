#ifndef TIMEDDEVICE_H
#define TIMEDDEVICE_H

#include "Arduino.h"
#include "../Rele/Rele.h"

/**
    Timed Device Class
    It manage a device with a working period (time being ON and time being OFF)
*/
class TimedDevice
{
    public:
        /**
            Contructor
            @param connected device pin number
            @param device ON status time
            @param device OFF status time
        */
        TimedDevice(int, unsigned long, unsigned long);

        /**
            Get connected device pin number
        */
        int getPinNum();
        /**
            Get device OFF status time
        */
        unsigned long getOffTime();
        /**
            Get device ON status time
        */
        unsigned long getOnTime();
        /**
            Get if device status is ON
        */
        boolean getEnabled();
        /**
            Set device OFF status time 
            @param desired device OFF status time
        */
	    unsigned long setOffTime(unsigned long);
        /**
            Set device ON status time
            @param desired device ON status time
        */
        unsigned long setOnTime(unsigned long);
        /**
            Update status device depending times setted and current counted time
        */
        boolean updateStatus();

    private:
        Rele* rele;
        int pinNum;
        unsigned long offTime;
        unsigned long onTime;
	    unsigned long currentTime;
        boolean enabled;

        /**
            Increase the current time counter
        */
	    unsigned long increaseCurrentTime();
        /**
            Reset (with value 0) the current time counter
        */
	    void resetCurrentTime();
};

TimedDevice::TimedDevice(int pin, unsigned long newOnTime, unsigned long newOffTime)
{
    pinNum = pin;
    onTime = newOnTime;
    offTime = newOffTime;
    enabled = false;
    currentTime = 0;

    rele = new Rele(pin);
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
        rele->disable();
        enabled = false;
        resetCurrentTime();
    } else if (time >= offTime && enabled == false) {
        rele->enable();
        enabled = true;
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


#endif
