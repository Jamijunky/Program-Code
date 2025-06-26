#include "Album.h"
#include <iostream>

Album::Album(DatabaseManager& db) : db(db) {}

bool Album::addAlbum(const std::string& name, int year) {
    std::string query = "INSERT INTO albums (name, year) VALUES (?, ?);";
    return db.executePrepared(query, {name, std::to_string(year)});
}

void Album::listAlbums() {
    std::cout << "📀 [Mock] Listing albums...\n";
    // You can later replace with actual DB query
}
