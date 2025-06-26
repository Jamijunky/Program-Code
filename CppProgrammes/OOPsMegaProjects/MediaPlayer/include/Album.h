#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "DatabaseManager.h"

class Album {
public:
    Album(DatabaseManager& db);
    bool addAlbum(const std::string& name, int year);
    void listAlbums(); // For now, basic console output
private:
    DatabaseManager& db;
};

#endif
