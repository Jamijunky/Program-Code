#include "Menu.h"
#include "DatabaseManager.h"
#include "Artist.h"
#include "Album.h"
#include "Song.h"
#include <iostream>

Menu::Menu(DatabaseManager& db)
    : artist(db), album(db), song(db) {}

void Menu::showMainMenu() {
    int choice;
    while (true) {
        std::cout << "\n🎵 Music Player - Main Menu 🎵\n";
        std::cout << "1. Manage Artists\n";
        std::cout << "2. Manage Albums\n";
        std::cout << "3. Manage Songs\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: artistMenu(); break;
            case 2: albumMenu(); break;
            case 3: songMenu(); break;
            case 0: std::cout << "Exiting...\n"; return;
            default: std::cout << "Invalid choice!\n";
        }
    }
}

void Menu::artistMenu() {
    int choice;
    std::string name, genre;

    std::cout << "\n👨‍🎤 Artist Menu\n";
    std::cout << "1. Add Artist\n";
    std::cout << "2. List Artists\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter artist name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter genre: ";
        std::getline(std::cin, genre);
        artist.addArtist(name, genre);
    } else if (choice == 2) {
        artist.listArtists();
    }
}

void Menu::albumMenu() {
    int choice, year;
    std::string name;

    std::cout << "\n💿 Album Menu\n";
    std::cout << "1. Add Album\n";
    std::cout << "2. List Albums\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter album name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter release year: ";
        std::cin >> year;
        album.addAlbum(name, year);
    } else if (choice == 2) {
        album.listAlbums();
    }
}

void Menu::songMenu() {
    int choice, duration, album_id, artist_id;
    std::string title, filepath;

    std::cout << "\n🎶 Song Menu\n";
    std::cout << "1. Add Song\n";
    std::cout << "2. List Songs\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter song title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << "Enter duration (in seconds): ";
        std::cin >> duration;
        std::cin.ignore();
        std::cout << "Enter file path: ";
        std::getline(std::cin, filepath);
        std::cout << "Enter album ID: ";
        std::cin >> album_id;
        std::cout << "Enter artist ID: ";
        std::cin >> artist_id;
        song.addSong(title, duration, filepath, album_id, artist_id);
    } else if (choice == 2) {
        song.listSongs();
    }
}
