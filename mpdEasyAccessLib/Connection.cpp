/*
 * Connection.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: richard
 */

#include "Connection.h"

namespace mpdAccess {

struct mpd_connection* Connection::connectionToMaster = nullptr;

Connection::Connection(std::string address) throw(char*) {
	if (address.find("/") != std::string::npos)
	{
		Connection::connectionToMaster = mpd_connection_new(address.c_str(), 0, 0);
	}
	else
	{
		Connection::connectionToMaster = mpd_connection_new(address.c_str(), 0, 0);
	}
	printf("Connection returned, checking for error\n");

	if (Connection::connectionToMaster == nullptr)
	{
		printf("Connection is nullptr\n");
		throw("Connection is nullptr");
	}
	else if (mpd_connection_get_error(Connection::connectionToMaster) != MPD_ERROR_SUCCESS)
	{
		printf("Connection refused, %s\n", mpd_connection_get_error_message(Connection::connectionToMaster));
		throw (mpd_connection_get_error_message(Connection::connectionToMaster));
	}

}

Connection::~Connection() {
	if (Connection::connectionToMaster != nullptr)
		mpd_connection_free(Connection::connectionToMaster);
}

struct mpd_connection* Connection::getConnection()
{
	return Connection::connectionToMaster;
}

} /* namespace mpdAccess */
