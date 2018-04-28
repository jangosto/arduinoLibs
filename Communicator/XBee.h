#ifndef XBEE_H
#define XBEE_H

#include <string.h>
#include "Arduino.h"

/**
    XBee Class
    It manages XBee actions
*/
class XBee
{
    public:
        /**
            Constructor
        */
        XBee();

        /**
            Send a message
            @param message
        */
        boolean sendMessage(char*);
        /**
            Get received message
        */
        char* getMessage();

    private:
        char messageOut[30];
        char messageIn[30];

        /**
            Set a message in message out buffer
            @param message
        */
        boolean setMessage(char*);
        /**
            Send message setted in out buffer
        */
        boolean send();
}

XBee::XBee()
{
}

boolean XBee::sendMessage(char* msg)
{
    setMessage(msg);
    send();
}

boolean XBee::setMessage(char* msg)
{
    return !(strcmp(strcpy(message, msg), msg));
}

boolean XBee::send()
{
    return !!(Serial.print(message));
}
