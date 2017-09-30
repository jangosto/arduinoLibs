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
}

#endif
