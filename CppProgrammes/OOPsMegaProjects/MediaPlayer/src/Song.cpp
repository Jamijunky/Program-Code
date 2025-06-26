#include "Song.h"
#include <iostream>

Song::Song(DatabaseManager& db) : db(db) {}

bool Song::addSong(const std::string& title, int duration, const std::string& filepath, int albumId, int artistId) {
    std::string query = "INSERT INTO songs (title, duration, filepath, album_id, artist_id) "
                        "VALUES (?, ?, ?, ?, ?);";
    return db.executePrepared(query, {
        title, std::to_string(duration), filepath,
        std::to_string(albumId), std::to_string(artistId)
    });
}

void Song::listSongs() {
    std::cout << "🎵 [Mock] Listing songs...\n";
    // Replace with real DB fetch later
}
