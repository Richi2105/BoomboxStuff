/*
 * Playback.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: richard
 */

#include "Playback.h"

namespace mpdAccess {

Playback::Playback()
{
	this->currentSong = nullptr;
}

Playback::~Playback() {
	// TODO Auto-generated destructor stub
}


void Playback::setPlayback(Playback::playback_operation operation)
{
	switch (operation)
	{
	case Playback::PLAY: mpd_run_play(Connection::getConnection()); this->currentState = PLAY; break;
	case Playback::PLAYPAUSE: mpd_run_toggle_pause(Connection::getConnection()); this->currentState = PLAYPAUSE; break;
	case Playback::STOP: mpd_run_stop(Connection::getConnection()); this->currentState = STOP; break;
	case Playback::NEXT: mpd_run_next(Connection::getConnection()); this->currentState = PLAY; break;
	case Playback::PREVIOUS: mpd_run_previous(Connection::getConnection()); this->currentState = PLAY; break;
	default: break;
	}
}

std::string Playback::getCurrentSongInfo(Playback::song_property property)
{
	printf("in Playback::getCurrentSongInfo\n");
	int error = mpd_connection_get_error(Connection::getConnection());
	printf("Error: %d\n", error);
	this->currentSong = mpd_run_current_song(Connection::getConnection());
	error = mpd_connection_get_error(Connection::getConnection());
	printf("Error: %d\n", error);

	std::string retVal;

	if (this->currentSong == nullptr)
		retVal = "ERROR";

	else
	{
		switch (property)
		{
		case Playback::ALBUM: retVal = mpd_song_get_tag(this->currentSong, MPD_TAG_ALBUM, 0); printf("%s\n", retVal.c_str()); break;
		case Playback::ARTIST: retVal = mpd_song_get_tag(this->currentSong, MPD_TAG_ARTIST, 0); printf("%s\n", retVal.c_str()); break;
		case Playback::TITLE: retVal = mpd_song_get_tag(this->currentSong, MPD_TAG_TITLE, 0); printf("%s\n", retVal.c_str()); break;
		case Playback::YEAR: retVal = mpd_song_get_tag(this->currentSong, MPD_TAG_DATE, 0); printf("%s\n", retVal.c_str()); break;
		case Playback::TRACKNR: retVal = mpd_song_get_tag(this->currentSong, MPD_TAG_TRACK, 0); printf("%s\n", retVal.c_str()); break;
		default: retVal = ""; printf("%s\n", retVal.c_str()); break;
		}
	}
	return retVal;
}

Playback::playback_operation Playback::getState()
{
	return this->currentState;
}

} /* namespace mpdAccess */
