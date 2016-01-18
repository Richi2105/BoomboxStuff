/*
 * Playback.h
 *
 *  Created on: Jan 5, 2016
 *      Author: richard
 */

#ifndef PLAYBACK_H_
#define PLAYBACK_H_

#include <mpd/client.h>
#include "Connection.h"

#include <string>

namespace mpdAccess {

class Playback {
public:
	enum playback_operation {PLAY, PLAYPAUSE, STOP, NEXT, PREVIOUS};
	enum song_property{TITLE, ARTIST, ALBUM, TRACKNR, YEAR};

	Playback();
	virtual ~Playback();

	void setPlayback(Playback::playback_operation operation);
	std::string getCurrentSongInfo(Playback::song_property property);

	playback_operation getState();

private:
	struct mpd_song* currentSong;
	playback_operation currentState;
};

} /* namespace mpdAccess */

#endif /* PLAYBACK_H_ */
