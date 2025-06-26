#pragma once
#include <string>
#include <vector>
#include "DatabaseManager.h"

class Artist {
public:
    explicit Artist(DatabaseManager& db);

    bool addArtist(const std::string& name, const std::string& genre);
    std::vector<std::string> listArtists();

private:
    DatabaseManager& db_;
};
