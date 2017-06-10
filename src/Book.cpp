#include "Book.h"

Book::Book(string name, int pageNumber)
{
    this->name = name;
    this->pageNumber = pageNumber;
}
Book::Book()
{
}
Book::Book(vector<string> tmp)
{
    this->name = tmp.at(0);
    istringstream buffer(tmp.at(1));
    buffer >> this->pageNumber;
}
void Book::setName(string name)
{
    this->name = name;
}
void Book::setPage(int pageNumber){
    this->pageNumber = pageNumber;
}
int Book::getPage(){
    return this->pageNumber;
}
string Book::getName()
{
    return this->name;
}
vector<string> Book::printData(){

    vector<string> tmp;
    tmp.push_back(this->name);
    stringstream ss;
    ss << this->pageNumber;
    tmp.push_back(ss.str());
    return tmp;

}
Book::~Book()
{
    //dtor
}
