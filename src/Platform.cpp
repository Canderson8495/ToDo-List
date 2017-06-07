#include "Platform.h"

Platform::Platform()
{
    //ctor
}

Platform::~Platform()
{
    //dtor
}
void Platform::setName(string tmpName)
{
    this->name = tmpName;
}
string Platform::getName()
{
    return this->name;
}
