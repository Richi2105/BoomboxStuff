/*
 * Playlist.h
 *
 *  Created on: Jan 7, 2016
 *      Author: richard
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
#include <vector>

#include "Connection.h"

#define DEBUG_OUT

namespace mpdAccess {

class Playlist {
public:
	Playlist();
	virtual ~Playlist();

	void reload();
	void setPlayAll();

	std::vector<std::string>* getArtistList();
	std::vector<std::string>* getAlbumList();
	std::vector<std::string>* getTitleList();

	std::vector<std::string>* obtainArtistByTag(mpd_tag_type tag = MPD_TAG_UNKNOWN, std::string value = "");
	std::vector<std::string>* obtainAlbumByTag(mpd_tag_type tag = MPD_TAG_UNKNOWN, std::string value = "");
	std::vector<std::string>* obtainSongsByTag(mpd_tag_type tag = MPD_TAG_UNKNOWN, std::string value = "");

private:
	std::vector<std::string>* artistList;
	std::vector<std::string>* albumList;
	std::vector<std::string>* titleList;

	void fillVector(std::vector<std::string>* vect, mpd_tag_type type, mpd_tag_type filter, std::string filterwhat);


};

} /* namespace mpdAccess */

#endif /* PLAYLIST_H_ */
