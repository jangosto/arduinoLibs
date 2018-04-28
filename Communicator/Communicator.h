#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <string.h>
#include "Arduino.h"

/**
    Communicator Class.
    It manages communication protocol
*/
class Communicator
{
    public:
        /**
            Construct
            @param communicator address
        */
        Communicator(char*);

        /**
            Get address
        */
        char* getAddress();
        /**
            Send a command without value
            @param destination address
            @param command
        */
        char* sendCommand(char*, char*);
        /**
            Send a command with value
            @param destination address
            @param command
            @param value
        */
        char* sendCommand(char*, char*, char*);
        /**
            Resend last command
        */
        char* resend();

    private:
        char address[10];
        char rxCommand[30];
        char txAddress[10];
        char txAction[10];
        char txValue[10];
        char txCommand[30];;

        /**
            Set address
            @param address
        */
        boolean setAddress(char*);
        /**
            Set command
            @param command
        */
        boolean setCommand(char*);
        /**
            Set destination address
            @param destination address
        */
        boolean setDestAddress(char*);
        /**
            Set value
            @param command value
        */
        boolean setValue(char*);
        /**
            
        */
}
