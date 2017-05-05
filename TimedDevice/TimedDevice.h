#ifndef TIMEDDEVICE_H
#define TIMEDDEVICE_H

#include "TimeOne.h"
#include "Rele.h"

class TimedDevice
{
    public:
        TimedDevice(int, unsigned long, unsigned long);

        int getPinNum();
        unsigned long getOffTime();
        unsigned long getOnTime();
        boolean getEnabled();
        boolean enable();
        boolean disable();        
        Rele getRele();

    private
        Rele rele
        int pinNum;
        unsigned long offTime;
        unsigned long onTime;
        boolean enabled;

        int setPinNum(int);
        unsigned long setOffTime(unsigned long);
        unsigned long setOnTime(unsigned long);
        boolean setEnabled(boolean);
        Rele setRele(Rele);
}

#endif
