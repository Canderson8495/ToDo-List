#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <string>

using namespace std;
class Platform
{
    public:
        Platform();
        virtual ~Platform();
        virtual void setName(string tmpName);
        virtual string getName();
    protected:
        string name;
    private:
};

#endif // PLATFORM_H
