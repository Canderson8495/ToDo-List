#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Game.h"
#include "Book.h"
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
        vector<vector<Platform*>> getDatabase();
        void setDatabase(vector<vector<Platform*>> tmp);
        vector<string> getCategoriesInUse();
        void setCategoriesInUse(vector<string> tmp);
        vector<string> getPossibleCategories();
        void setPossibleCategories(vector<string> tmp);
        void addEntry(vector<string> entryData);
        void deleteEntry(int index, vector<vector<Platform*>>);
        vector<vector<Platform*>> searchEntry(string tmp);
        void addPlatform();
        virtual ~Database();
    protected:

    private:
        //void chooseData(vector<vector<*Platform>> tmpDatabase);
        vector<string> categories = {"Games"};
        vector<Game> games;
        vector<Book> books;
        vector<Platform*> platforms;
        vector<vector<Platform*>> database;
        vector<string> possibleCategories = {"Books", "Games"};
        vector<string> categoriesInUse;
};

#endif // DATABASE_H
