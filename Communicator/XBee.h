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
        boolean setMessageIn(char*);
        /**
            Set a message in message in buffer
            @param message
        */
        boolean setMessageOut(char*);
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
    setMessageOut(msg);
    send();
}

boolean XBee::setMessageOut(char* msg)
{
    return !(strcmp(strcpy(messageOut, msg), msg));
}

boolean XBee::setMessageIn(char* msg)
{
    return !(strcmp(strcpy(messageIn, msg), msg));
}

boolean XBee::send()
{
    return !!(Serial.print(messageOut));
}
