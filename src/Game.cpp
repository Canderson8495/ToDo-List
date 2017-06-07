#include "Game.h"

Game::Game()
{
    //ctor
}

void Game::setName(string tmpName)
{
    this->name = tmpName;
}

void Game::setConsole(string tmpConsole)
{
    this->console = tmpConsole;
}

string Game::getName()
{
    return this->name;
}

string Game::getConsole()
{
    return this->console;
}

Game::~Game()
{
    //dtor
}
