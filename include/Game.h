#ifndef GAME_H
#define GAME_H
#include "Platform.h"
#include <iostream>
using namespace std;
class Game: public Platform
{
    public:
        Game(vector<string> tmp);
        Game();
        void setName(string name);
        string getName();
        void setConsole(string console);
        string getConsole();
        vector<string> printData();
        virtual ~Game();

    protected:

    private:
        string console;
};

#endif // GAME_H
