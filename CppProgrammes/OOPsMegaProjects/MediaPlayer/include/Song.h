#ifndef SONG_H
#define SONG_H

#include <string>
#include "DatabaseManager.h"

class Song {
public:
    Song(DatabaseManager& db);
    bool addSong(const std::string& title, int duration, const std::string& filepath, int albumId, int artistId);
    void listSongs(); // Basic console output
private:
    DatabaseManager& db;
};

#endif
