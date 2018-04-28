#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <string.h>
#include "Arduino.h"
#include "Xbee.h"

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
        char rxAdress[10];
        char rxAction[10];
        char rxValue[10];
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
            Set Rx command
            @param command
        */
        boolean setRxCommand(char*);
        /**
            Set Rx address
            @param destination address
        */
        boolean setRxAddress(char*);
        /**
            Set action for Rx command
            @param command action
        */
        boolean setRxAction(char*);
        /**
            Set value for Rx command
            @param command value
        */
        boolean setRxValue(char*);
        /**
            Set Rx address, action and value from Rx command
        */
        boolean decodeRxCommand();
        /**
            Set Tx command
            @param command
        */
        boolean setTxCommand(char*);
        /**
            Set Tx address
            @param destination address
        */
        boolean setTxAddress(char*);
        /**
            Set action for Tx command
            @param command action
        */
        boolean setTxAction(char*);
        /**
            Set value for Tx command
            @param command value
        */
        boolean setTxValue(char*);
        /**
            Set Tx command from Tx address, action and value
        */
        boolean encodeTxCommand();
}

Comunicator::Communicator(char* address)
{
    setAddress(address);
}

char* getAddress()
{
    return address;
}

char* sendCommand(char* address, char* action)
{
    Xbee* xbee = new Xbee();

    setTxAddress(address);
    setTxAction(action);
    encodeTxCommand();

    return xbee->sendMessage(txCommand);
}

char* sendCommand(char* address, char* action, char* value)
{
    Xbee* xbee = new Xbee();

    setTxAddress(address);
    setTxAction(action);
    setTxValue(value);
    encodeTxCommand();

    return xbee->sendMessage(txCommand);
}

boolean encodeTxCommand()
{

}

char* resend()
{
    return xbee->sendMessage(txCommand);
}

boolean setAddress(char* assignedAddress)
{
    return !(strcmp(strcpy(address, assignedAddress), assignedAddress));
}

boolean setRxCommand(char* command)
{
    return !(strcmp(strcpy(rxCommand, command), command));
}

boolean setRxAddress(char* address)
{
    return !(strcmp(strcpy(rxAddress, address), address));
}

boolean setRxAction(char* action)
{
    return !(strcmp(strcpy(rxAction, action), action));
}

boolean setRxValue(char* value)
{
    return !(strcmp(strcpy(rxValue, value), value));
}

boolean setTxCommand(char* command)
{
    return !(strcmp(strcpy(txCommand, command), command));
}

boolean setTxAddress(char* address)
{
    return !(strcmp(strcpy(txAddress, address), address));
}

boolean setTxAction(char* action)
{
    return !(strcmp(strcpy(txAction, action), action));
}

boolean setTxValue(char* value)
{
    return !(strcmp(strcpy(txValue, value), value));
}
