#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;
class Game
{
    public:
        Game();
        virtual ~Game();
        void setName(string tmpName);
        void setConsole(string tmpConsole);
        string getName();
        string getConsole();
    protected:

    private:
        string console;
        string name;
};

#endif // GAME_H
