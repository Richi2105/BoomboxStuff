/*
 * Logger.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: richard
 */

#include <Telegram/TelegramObject.h>
#include <constants.h>
#include <Logging/Log.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>
#include <EventSystemClient.h>
#include <netinet/in.h>

//#define network

using namespace std;
using namespace EventSystem;

int main(void)
{
	sockaddr_in masterLocation;
	struct in_addr masterAddress;
	inet_aton("192.168.2.115", &masterAddress);
	masterLocation.sin_addr = masterAddress;
	masterLocation.sin_port = PORT;
	masterLocation.sin_family = AF_INET;

	char networkDevice[] = "eth0";

#ifdef network
	EventSystemClient espi(Telegram::ID_LOGGER, PORT, networkDevice);
	espi.connectToMaster(masterLocation);
#else
	EventSystemClient espi("LOGGER");
	espi.connectToMaster();
	espi.startReceiving();
#endif //network
//	Telegram_Log* log = new Telegram_Log();
	Telegram_Object* objTelegram = new Telegram_Object();
	Log* log = new Log();

	void* data = malloc(4096);

	while (true)
	{
		espi.receive(data, false);
		objTelegram->deserialize(data, log);
//		log->deserialize(data);
		time_t currtime = log->getTime();
		cout << "\n\non " << ctime(&currtime) << "\n" << "From " << log->getUniqueSourceID() << "\n" << log->getLog() << endl;
	}
}


