/*
 * master.cpp
 *
 *  Created on: Nov 21, 2015
 *      Author: richard
 */

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <EventSystemMaster.h>

#define DEBUG_OUT

using namespace std;

int main(void)
{
	cout << "in main()" << endl;

	EventSystem::EventSystemMaster* master = new EventSystem::EventSystemMaster();
	cout << "ID is: " << master->getUniqueIdentifier() << endl;

	while (true)
	{
		sleep(100);
	}


	return 0;
}


