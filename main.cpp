#include <iostream>
#include "Database.h"
using namespace std;
int main()
{
    cout << "STAGE 1: DATABASE INITIALIZATION" << endl;
    cout << "Welcome to your personal database. You can input TV shows, movies, and much more with the simple click of a button!" << endl;
    cout << "Do you currently have a database?[Y/N]" << endl;
    char answer;
    cin >> answer;
    Database tmp;
    /**
        THIS WILL EITHER LOAD OR CREATE A NEW DATABASE.
        DATABASE SAVES WILL BE DONE MOST LIKELY AFTER EACH INDIVIDUAL ENTRY CHANGE AND ON QUIT.
    **/
    if(toupper(answer)=='N'){

        cout << "CREATING DATABASE NOW" << endl;
        //create database here,  but basically will create a new file.
        cout << "DATABASE CREATED" << endl;
    }else{
        cout << "OPENING DATABASE" << endl;
        //load database here, the issue is that i have not figured out how to really save the entire base, so that it will efficient loading, closing, and saving it.
        cout << "DATABASE OPENED" << endl;
    }
    /*
    STAGE 2 BEGINS HERE...
    */
    while(toupper(answer)!='Q'){
    cout << "STAGE 2: DATABASE DISPLAYING" << endl;
    /**
        THIS DISPLAYS DATA BASE
        tmp.displayData()
        if EMPTY. A NULL CHECK WILL HANDLE IT
        else The database will display only the games section.
        I plan on making a vector<vector<*platforms>> so i can iterate through all the lists with 2 for loops.
    **/
    tmp.displayData();
    cout << "\n\n\nSTAGE 3: DATABASE CHANGES" << endl;
    /**
        DATABASE CHANGES WILL BE CONDUCTED WITH A FEW PREDETERMINED OPTIONS SUCH AS...
        addEntry(), deleteEntry(), searchEntry(), and to be added editEntry()
    **/
    cout << "Would you like to make any changes to your database" << endl << endl;
    cout << "Supported functions:" << endl;
    cout << "A: ADD ENTRY" << endl;
    cout << "S: DELETE ENTRY" << endl;
    cout << "D: SEARCH ENTRY" << endl;
    cout << "Q: QUIT PROGRAM" << endl;
    cin >> answer;
    switch(toupper(answer)){
    case 'A':
        cout << "ADDING ENTRY" << endl;
        tmp.addEntry();
        break;
    case 'S':
        cout << "DELETING ENTRY" << endl;
        tmp.deleteEntry();
        break;
    case 'D':
        cout << "SEARCHING ENTRY" << endl;
        tmp.searchEntry();
        break;
    case 'Q':
        break;
    }
    }
    return 0;
}
