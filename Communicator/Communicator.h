#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <string.h>
#include "Arduino.h"
#include "Xbee.h"

#define COMMAND_PREFIX "**"
#define COMMAND_SUFIX "**"
#define COMMAND_PART_SEPARATOR "_"

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
            Reset Rx attributes to NULL
        */
        boolean resetRx();
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
            Reset Tx attributes to NULL
        */
        boolean resetTx();
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

    resetTx();
    setTxAddress(address);
    setTxAction(action);
    encodeTxCommand();

    return xbee->sendMessage(txCommand);
}

char* sendCommand(char* address, char* action, char* value)
{
    Xbee* xbee = new Xbee();

    resetTx();
    setTxAddress(address);
    setTxAction(action);
    setTxValue(value);
    encodeTxCommand();

    return xbee->sendMessage(txCommand);
}

boolean resetTx()
{
    txAddress = NULL;
    txAction = NULL;
    txValue = NULL;
}

boolean encodeTxCommand()
{
    char message[30];

    sprintf(message, "%s%s%s%s", COMMAND_PREFIX, txAddress, COMMAND_PART_SEPARATOR, txAction);

    if (txValue != NULL && strlen(txValue) > 0) {
        sprintf(message, "%s%s%s", message, COMMAND_PART_SEPARATOR, txValue);
    }

    sprintf(message, "%s%s", message, COMMAND_SUFIX);

    return true;
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
