#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <vector>
using namespace std;
class Platform
{
    public:
        Platform();
        virtual void setName(string name);
        virtual string getName();
        virtual vector<string> printData() = 0;
        virtual ~Platform();
    protected:
        string name;
    private:

};

#endif // PLATFORM_H
