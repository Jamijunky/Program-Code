#pragma once

#include "DatabaseManager.h"
#include "Artist.h"
#include "Album.h"
#include "Song.h"

class Menu {
public:
    Menu(DatabaseManager& db);
    void showMainMenu();

private:
    Artist artist;
    Album album;
    Song song;

    void artistMenu();
    void albumMenu();
    void songMenu();
};
