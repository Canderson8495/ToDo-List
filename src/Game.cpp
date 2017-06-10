#include "Game.h"

Game::Game()
{
    //ctor
}
Game::Game(vector<string> tmp)
{
    this->name = tmp.at(0);
    this->console = tmp.at(1);
}
void Game::setName(string name)
{
    this->name = name;
}
void Game::setConsole(string console){
    this->console = console;
}
string Game::getConsole()
{

    return this->console;
}
string Game::getName()
{
    return this->name;
}
vector<string> Game::printData(){

    vector<string> tmp;
    tmp.push_back(this->name);
    tmp.push_back(this->console);
    return tmp;

}
Game::~Game()
{
    //dtor
}
