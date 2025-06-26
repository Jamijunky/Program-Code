#include "Artist.h"
#include <iostream>

Artist::Artist(DatabaseManager& db) : db_(db) {}

bool Artist::addArtist(const std::string& name, const std::string& genre) {
    std::string query = "INSERT INTO artists (name, genre) VALUES ('" + name + "', '" + genre + "');";
    return db_.executeQuery(query);
}

std::vector<std::string> Artist::listArtists() {
    // For simplicity, return dummy data now
    return {"Artist 1", "Artist 2", "Artist 3"};
}
