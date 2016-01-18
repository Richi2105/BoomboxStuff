/*
 * Connection.h
 *
 *  Created on: Jan 7, 2016
 *      Author: richard
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <mpd/client.h>
#include <string>
#include <exception>

namespace mpdAccess {

class Connection {
public:
	Connection(std::string address) throw (char*);
	virtual ~Connection();

	static struct mpd_connection* getConnection();
private:
	static struct mpd_connection* connectionToMaster;
};

} /* namespace mpdAccess */

#endif /* CONNECTION_H_ */
