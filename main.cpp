#include <iostream>
#include "Database.h"
using namespace std;


void displayDatabase(Database tmp);

int main()
{
    cout << "STAGE 1: DATABASE INITIALIZATION" << endl;
    cout << "Welcome to your personal database. You can input TV shows, movies, and much more with the simple click of a button!" << endl;
    cout << "Do you currently have a database?[Y/N]" << endl;
    char answer;
    string tmpString;
    int intAnswer;
    cin >> answer;
    Database mainData;
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
    displayDatabase(mainData);
    cout << "\n\n\nSTAGE 3: DATABASE CHANGES" << endl;
    /**
        DATABASE CHANGES WILL BE CONDUCTED WITH A FEW PREDETERMINED OPTIONS SUCH AS...
        addEntry(), deleteEntry(), searchEntry(), and to be added editEntry()
    **/
    cout << "Would you like to make any changes to your database" << endl << endl;
    cout << "Supported functions:" << endl;
    cout << "P: ADD PLATFORM" << endl;
    cout << "A: ADD ENTRY" << endl;
    cout << "S: DELETE ENTRY" << endl;
    cout << "D: SEARCH ENTRY" << endl;
    cout << "Q: QUIT PROGRAM" << endl;
    cin >> answer;
    switch(toupper(answer)){
    case 'A':
        cout << "ADDING ENTRY" << endl;
        mainData.addEntry();
        break;
    case 'S':
        cout << "DELETING ENTRY" << endl;
        cout << "You have decided to delete an entry" << endl;
        cout << "Type in the keyword associated with that entry" << endl;
        cin >> tmpString;
        tmp.setDatabase(mainData.searchEntry(tmpString));
        tmp.setCategoriesInUse(mainData.getCategoriesInUse());
        displayDatabase(tmp);

        cout << "Which entry would you like to delete[1/2/3/4/....]"<< endl;
        cin >> intAnswer;
        /*
        delete entry will look at the data stored at index #tmp, and
        it'll compare that to data found in main database, when it finds a
        complete match, then we'll know which index it really lies at inside of the main database.
         Then we'll just simply delete from the database and possibly delete from the respective platform vector
        */
        mainData.deleteEntry(intAnswer, tmp.getDatabase());
        break;
    case 'D':
        cout << "SEARCHING ENTRY" << endl;
        cout << "What keyword would you like to search?" << endl;
        cin >> tmpString;

        tmp.setDatabase(mainData.searchEntry(tmpString));
        tmp.setCategoriesInUse(mainData.getCategoriesInUse());
        displayDatabase(tmp);
        break;
    case 'Q':
        break;
    case 'P':
        mainData.addPlatform();
        break;
    }
    }
    return 0;
}



void displayDatabase(Database tmp){
    vector<vector<Platform*>> database = tmp.getDatabase();
    vector<string> tmpEntryData;
    vector<Platform*> platforms;
    vector<string> categoriesInUse = tmp.getCategoriesInUse();
    int index = 0;
    for(int x = 0; x < database.size(); x++){
        if(categoriesInUse.at(x)== "Games"){
            cout << "GAMES" << endl;
            cout << "Name" << "       Console" << endl;
        }else if(categoriesInUse.at(x) == "Books"){
            cout << "BOOKS" << endl;
            cout << "Name" << "       Total Pages" << endl;
        }
        platforms = database.at(x);
        if(platforms.size()==0){
            cout << "NO DATA FOUND FOR " << categoriesInUse.at(x) << endl;
        }
        for(int c = 0; c < platforms.size(); c++){
            index++;
            cout << index << ": ";
            tmpEntryData = platforms.at(c)->printData();
            for(int j = 0; j < tmpEntryData.size(); j++){
                cout << tmpEntryData.at(j) << "    ";
            }
            cout << endl;
        }
    }
}
