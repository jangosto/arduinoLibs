#ifndef TIMEDDEVICE_H
#define TIMEDDEVICE_H

#include <Rele.h>

class TimedDevice
{
    public:
        TimedDevice(int, unsigned long, unsigned long);

        int getPinNum();
        unsigned long getOffTime();
        unsigned long getOnTime();
        boolean getEnabled();
	unsigned long setOffTime(unsigned long);
        unsigned long setOnTime(unsigned long);
        boolean updateStatus();

    private
        Rele rele
        int pinNum;
        unsigned long offTime;
        unsigned long onTime;
	unsigned long currentTime;
        boolean enabled;

	unsigned long increaseCurrentTime();
	void resetCurrentTime();
}

#endif
