#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <sstream>
#include <string>
#include "Platform.h"
using namespace std;
class Book: public Platform
{
    public:
        Book(string name, int pageNumber);
        Book();
        Book(vector<string> tmp);
        void setName(string name);
        void setPage(int pageNumber);
        string getName();
        int getPage();
        virtual ~Book();
        vector<string> printData();
    protected:

    private:
        int pageNumber;
};

#endif // BOOK_H
