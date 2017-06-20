#include <iostream>
#include <fstream>
#include <sstream>
#include "Database.h"
using namespace std;


void displayDatabase(Database tmp);
void saveDatabase(Database save);

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

        cout << "DATABASE CREATED" << endl;
    }else{
        cout << "OPENING DATABASE" << endl;
        /**
        LOADING DATABASE
        **/
        string stringAnswer, tmp, category;
        int convert;
        vector<string> entryData;
        vector<vector<string>> Database;
        vector<string> categoriesInUse;
        vector<string> possibleCategories;
        ifstream reader("Database.txt");
        while(reader.good()){
            reader >> stringAnswer;
            cout << "STRING ANSWER IS " << stringAnswer << endl;
            if(stringAnswer == "0" || stringAnswer== "1" || stringAnswer== "2" || stringAnswer== "3"){
                entryData.push_back(stringAnswer);
                cout << "INITATING ENTRY SEARCHER" << endl;
                getline(reader, stringAnswer);
                //CHECK FOR AMOUNT OF WORDS.
                tmp = "";
                for(int t = 0; t < stringAnswer.size(); t++){
                    if(stringAnswer.at(t)!= '|'){
                        if(tmp.size()== 0){
                            tmp = stringAnswer.at(t);
                        }else{
                            tmp += stringAnswer.at(t);
                        }
                    }else{
                        cout << "NEW ONE FOUND" << endl;
                        entryData.push_back(tmp);
                        tmp = "";
                    }
                }
                tmp = "";
                mainData.addEntry(entryData);
                entryData.clear();
                cout << endl;

            }else if(stringAnswer == "USEDCATEGORIES"){
                reader >> stringAnswer;
                stringstream ss(stringAnswer);
                ss >> convert;
                vector<vector<Platform*>> tmp;
                vector<Platform*> platforms;
                for(int x = 0; x < convert; x++){
                    reader >> stringAnswer;
                    categoriesInUse.push_back(stringAnswer);
                    tmp.push_back(platforms);
                    cout << categoriesInUse.at(x) << endl;
                }
                mainData.setCategoriesInUse(categoriesInUse);
                mainData.setDatabase(tmp);

            }else if(stringAnswer == "POSSIBLECATEGORIES"){
                reader >> stringAnswer;
                stringstream ss(stringAnswer);
                ss >> convert;
                for(int x = 0; x < convert; x++){
                    reader >> stringAnswer;
                    possibleCategories.push_back(stringAnswer);
                    cout << possibleCategories.at(x) << endl;
                }
                mainData.setPossibleCategories(possibleCategories);
            }
        }
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
    case 'A':{
        vector<string> entryData;
        system("cls");
        cout << "You are adding a entry" << endl;
        cout << "What category will your entry be in?" << endl;
        vector<string> categoriesInUse = mainData.getCategoriesInUse();
        for(int x = 0; x < categoriesInUse.size(); x++){
            cout << x << ": " << categoriesInUse.at(x) << endl;
        }
        cin >> intAnswer;
        stringstream ss;
        ss << intAnswer;
        entryData.push_back(ss.str());
        if(categoriesInUse.at(intAnswer)== "Games"){
            cout << "You have chosen to add a new game" << endl;
            cout << "What is the name of the game?" << endl;
            string stringAnswer;
            cin.ignore();
            getline(cin , stringAnswer);
            entryData.push_back(stringAnswer);
            cout << "What is the console of the game?" << endl;
            getline(cin,stringAnswer);
            entryData.push_back(stringAnswer);
        }else if(categoriesInUse.at(intAnswer) == "Books"){
            cout << "You have chosen to add a new book" << endl;
            cout << "What is the name of the book?" << endl;
            string stringAnswer;
            cin.ignore();
            getline(cin , stringAnswer);
            entryData.push_back(stringAnswer);
            cout << "What is the total page number of the book" << endl;
            int tmpInt;
            cin >> tmpInt;
            ss << tmpInt;
            entryData.push_back(ss.str());
        }
        mainData.addEntry(entryData);
        saveDatabase(mainData);
        break;
    }
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
        saveDatabase(mainData);
        break;
    case 'D':
        cout << "SEARCHING ENTRY" << endl;
        cout << "What keyword would you like to search?" << endl;
        cin >> tmpString;

        tmp.setDatabase(mainData.searchEntry(tmpString));
        tmp.setCategoriesInUse(mainData.getCategoriesInUse());
        displayDatabase(tmp);
        saveDatabase(mainData);
        break;
    case 'Q':
        break;
    case 'P':
        mainData.addPlatform();
        saveDatabase(mainData);
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


void saveDatabase(Database save){
    ofstream writer("Database.txt");
    if(writer.is_open()){
        vector<vector<Platform*>> database = save.getDatabase();
        vector<string> tmpEntryData;
        vector<Platform*> platforms;
        vector<string> categoriesInUse = save.getCategoriesInUse();
        vector<string> possibleCategories = save.getPossibleCategories();
        writer << "USEDCATEGORIES ";
        writer << categoriesInUse.size() << " ";
        for(int x = 0; x < categoriesInUse.size(); x++){
            writer << categoriesInUse.at(x) << " ";
        }
        writer << endl;
        writer << "POSSIBLECATEGORIES ";
        writer << possibleCategories.size() << " ";
        for(int x = 0; x < possibleCategories.size(); x++){
            writer << possibleCategories.at(x) << " ";
        }
        writer << endl;
        for(int x = 0; x < database.size(); x++){
            platforms = database.at(x);
            for(int c = 0; c < platforms.size(); c++){
                writer << x << " ";
                tmpEntryData = platforms.at(c)->printData();
                for(int j = 0; j < tmpEntryData.size(); j++){
                    writer << tmpEntryData.at(j) << " | ";
                }
                writer << endl;
            }
        }
    }else{
        cout << "ERROR SAVING FILE" << endl;
    }
}
