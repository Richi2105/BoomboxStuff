/*
 * Playlist.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: richard
 */

#include "Playlist.h"
#include <mpd/client.h>
#include <stdio.h>

namespace mpdAccess {

Playlist::Playlist() {
	this->artistList = new std::vector<std::string>();
	this->albumList = new std::vector<std::string>();
	this->titleList = new std::vector<std::string>();
}

Playlist::~Playlist() {
	// TODO Auto-generated destructor stub
}

void Playlist::reload()
{
	this->artistList->clear();

	struct mpd_pair* pair;
	mpd_send_command(Connection::getConnection(), "list", "artist", NULL);
	do
	{
		pair = mpd_recv_pair(Connection::getConnection());
		printf("Name: %s, value: %s\n", pair->name, pair->value);
		if (pair->value != NULL)
			this->artistList->push_back(pair->value);
		mpd_return_pair(Connection::getConnection(), pair);

	} while (pair != NULL);
}

std::vector<std::string>* Playlist::obtainArtistByTag(mpd_tag_type tag, std::string value)
{
	this->artistList->clear();
	this->fillVector(this->artistList, MPD_TAG_ARTIST, tag, value);

	return this->artistList;
}
std::vector<std::string>* Playlist::getArtistList()
{
	return this->artistList;
}

std::vector<std::string>* Playlist::obtainAlbumByTag(mpd_tag_type tag, std::string value)
{
	this->albumList->clear();
	this->fillVector(this->albumList, MPD_TAG_ALBUM, tag, value);

	return this->albumList;
}
std::vector<std::string>* Playlist::getAlbumList()
{
	return this->albumList;
}

std::vector<std::string>* Playlist::obtainSongsByTag(mpd_tag_type tag, std::string value)
{
	this->titleList->clear();
	this->fillVector(this->titleList, MPD_TAG_TITLE, tag, value);

	return this->titleList;
}
std::vector<std::string>* Playlist::getTitleList()
{
	return this->titleList;
}

void Playlist::setPlayAll()
{
}

void Playlist::fillVector(std::vector<std::string>* vect, mpd_tag_type type, mpd_tag_type filter, std::string filterwhat)
{
	struct mpd_pair* pair;
	if (filterwhat == "" || filter == MPD_TAG_UNKNOWN)
		mpd_send_command(Connection::getConnection(), "list", mpd_tag_name(type), NULL);
	else
		mpd_send_command(Connection::getConnection(), "list", mpd_tag_name(type), mpd_tag_name(filter), filterwhat.c_str(), NULL);

	while ( (pair = mpd_recv_pair(Connection::getConnection()) ) != NULL)
	{

#ifdef DEBUG_OUT
		printf("Name: %s, value: %s\n", pair->name, pair->value);
#endif //DEBUG_OUT
		if (pair->value != NULL)
			vect->push_back(pair->value);
		mpd_return_pair(Connection::getConnection(), pair);

	}
}

} /* namespace mpdAccess */
