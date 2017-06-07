#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Game.h"
using namespace std;
/**
    It's important to understand the terminology.
    TERMINOLOGY:
        DATA: Will often refer to database. EX: displayData() -> displays database
        ENTRY: Will refer to the individual piece of information in the database. EX: addEntry() -> Adds a new entry such as a new game.
        PLATFORM: Will refer to the area of entertainment being used. EX: organizePlatform() -> will organize all the EX: video games. into alphabetical order.
**/
class Database
{
    public:
        Database();
        void displayData();
        void addEntry();
        void deleteEntry();
        void searchEntry();
        void addPlatform();
        virtual ~Database();
    protected:

    private:
        vector<string> categories = {"Games"};
        vector<Game> games;
};

#endif // DATABASE_H
