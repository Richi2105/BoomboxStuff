/*
 * main.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: richard
 */

#include <DisplayCommunicationHardware.h>
#include <EventSystemClient.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Logging/LoggerAdapter.h>

#include <Telegram/Telegram.h>
#include <Telegram/TelegramObject.h>
#include <include/DisplayPosition.h>
#include <include/DisplayString.h>

using namespace std;
using namespace EventSystem;
using namespace DotMatrix;

int main()
{

	EventSystemClient* evp = new EventSystemClient(Telegram::ID_DISPLAY);
	evp->connectToMaster();
	evp->startReceiving();

	LoggerAdapter::initLoggerAdapter(evp);

	DisplayCommunicationHardware* commModule = new DisplayCommunicationHardware(122, 32);
    commModule->clearDisplay();
    DisplayString::setCommunicationModule(commModule);

    DisplayPosition* pos = new DisplayPosition();
    DisplayString* dispStr = new DisplayString();
    std::string s;

    void* telegram = malloc(4096);

    Telegram_Object* objTelegram = new Telegram_Object();
    Telegram* aTelegram = new Telegram("nothing");


    while (true)
    {
        printf("Function receive(): %d\n", evp->receive(telegram, false));
        aTelegram->deserialize(telegram);
        printf("Everything alright, telegram type is %d\n", aTelegram->getType());
        switch (aTelegram->getType())
        {
	case Telegram::REQUEST: {
		objTelegram->setType(Telegram::DISPLAYDIMENSION);
		objTelegram->setIdentifier(Telegram::ID_DISPLAYCLIENT);
		pos->setXPosition(122);
		pos->setYPosition(32);
		objTelegram->setObject(pos);
		evp->send(objTelegram);
		LoggerAdapter::log(Log::INFO, "Output: a client requested the display dimensions");
		break;
	}
	case Telegram::DISPLAYDATA: {
		printf("N bytes deserialized: %d\n", objTelegram->deserialize(telegram, dispStr));
		printf("Empfangen: %s\n", dispStr->getString().c_str());
		LoggerAdapter::log(Log::INFO, dispStr->getString());
		dispStr->display();
		break;
	}
	default: LoggerAdapter::log(Log::WARNING, "Output: Wrong telegram received");
        }

    }
    return 0;
}

