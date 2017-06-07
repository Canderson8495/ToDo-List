#include "Database.h"

Database::Database()
{
    //ctor
}

void Database::displayData()
{
    /**
    Unfortunatly, i've decided to hard code the display data after numerous failed attempts at other things, that is a bummer, but we'll explore more difficult options towards the release of the code.
    **/
    //GAME DISPLAY
    cout << "GAMES" << endl;
    cout << "Name" << "     " << "Console" << endl;
    for(int x = 0; x < games.size(); x++){
        cout << games.at(x).getName() << "     " << games.at(x).getConsole() << endl;
    }
}


/*
void Database::addPlatform()
{
    system("cls");
    cout << "You have chosen to add a new platform" << endl;
    cout << "Here is a list of the currently available platforms" << endl;
    if(possibleCategories.size()==0){
        cout << "   There are no categories available to be added!" << endl;
    }else{
        for(int x = 0; x < possibleCategories.size(); x++){
            cout << "   " << possibleCategories.at(x) << endl;
        }
        cout << "Please type whichever category you would like to add" << endl;
        string stringAnswer;
        cin >> stringAnswer;
        transform(stringAnswer.begin(), stringAnswer.end(), stringAnswer.begin(), ::toupper);
        vector<Platform*> tmpPlatform;
        if(stringAnswer == "GAMES"){
            cout << "You have decided to add a game" << endl;
            database.push_back(&tmpPlatform);
            auto it = find(possibleCategories.begin(), possibleCategories.end(), "Games");
            if(it != possibleCategories.end()){
                v.erase(it);
            }else{
                cout << "ERRRROROROROROROR" << endl;
            }
            categoriesInUse.push_back("Games");
        }
    }
}

*/

/**

I NEED TO GET BACK TO FIXING addEntry() AND searchEntry(), BECAUSE I WANT TO ADD A addPlatform() FUNCTION.

**/
void Database::addEntry()
{
    system("cls");
    cout << "You are adding a entry" << endl;
    cout << "What category will your entry be in?" << endl;
    for(int x = 0; x < categories.size(); x++){
        cout << x << ": " << categories.at(x) << endl;
    }
    int intAnswer;
    cin >> intAnswer;
    switch(intAnswer){
    case 0:
        cout << "You have chosen to add a new game" << endl;
        Game tmp;
        cout << "What is the name of the game?" << endl;
        string stringAnswer;
        cin.ignore();
        getline(cin , stringAnswer);
        tmp.setName(stringAnswer);
        cout << "What is the console of the game?" << endl;
        getline(cin,stringAnswer);
        tmp.setConsole(stringAnswer);
        games.push_back(tmp);
        cout << "You have created a new game entry with the game " << tmp.getName() << " thats run on the console " << tmp.getConsole() << endl;
        break;
    case 1:
        cout << "You have chosen to add a new book" << endl;
        break;
    }
}

void Database::deleteEntry()
{
    cout << "You are deleting a entry" << endl;
}

void Database::searchEntry()
{
    //ADD MULTIPLE DIFFERENT TYPES OF PLATFORMS LIKE BOOKS BY USING SOME EQUIVALENT TO vector<vector<*platforms>> or something of the similar
    /**
    Unfortunatly, this will be an absolute mess, because i'm looking for through hard coded lists, therefore i'll have to loop around for each platform... Games, Books, ETC..
    **/
    system("cls");
    cout << "You are searching a entry" << endl;
    cout << "What is the name of the entry" << endl;
    string stringAnswer;
    float tmpRatio;
    cin.ignore();
    getline(cin, stringAnswer);
    string tmp = "";
    vector<string> wordsInSearchQuery;
    vector<Game> searchResults;
    transform(stringAnswer.begin(), stringAnswer.end(), stringAnswer.begin(), ::toupper);
    //tmp2 is a replacement for games.at(x).getName(). I was getting a fpermissive error because i had it going to games.at(x).getName().at(n)
    for(int t = 0; t < stringAnswer.size(); t++){
        if(stringAnswer.at(t)!= ' '){
            if(tmp.size()== 0){
                tmp = stringAnswer.at(t);
            }else{
                tmp += stringAnswer.at(t);
            }
        }else{
            wordsInSearchQuery.push_back(tmp);
            tmp = "";
        }
    }
    wordsInSearchQuery.push_back(tmp);
    tmp = "";
    cout << "There were " << wordsInSearchQuery.size() << " words inside of " << stringAnswer << endl << endl;

    vector<float> ratioAlike;
    string tmp2;
    vector <string> tmpWordsInQuery;
    /**
    OH GOD THE HUMANITY
    **/
    for(int x = 0; x < games.size(); x++){
        tmp2 = games.at(x).getName();
        transform(tmp2.begin(), tmp2.end(), tmp2.begin(), ::toupper);
        for(int n = 0; n < tmp2.size(); n++){
            if(tmp2.at(n) != ' '){
                if(tmp.size()== 0){
                    tmp = tmp2.at(n);
                }else{
                    tmp += tmp2.at(n);
                }
            }else{
                tmpWordsInQuery.push_back(tmp);
                tmp = "";
            }
        }
        tmpWordsInQuery.push_back(tmp);
        tmp = "";
        cout << "There are " << tmpWordsInQuery.size() << " words inside of " << tmp2 << endl;

        //Here is where we look for similarities with the result words and the search words
        int charactersAlike = 0;
        cout << "Searching for matches against SearchQuery: " << stringAnswer << endl;
        for(int g = 0; g < wordsInSearchQuery.size(); g++){
            for(int o = 0; o < tmpWordsInQuery.size(); o++){
                if(wordsInSearchQuery.at(g).compare(tmpWordsInQuery.at(o))==0){
                    charactersAlike+=wordsInSearchQuery.at(g).size();
                    break;
                }
            }
        }
        cout << "There were " << charactersAlike << " characters alike between " << stringAnswer << " and " << tmp2 << endl << endl;
        cout << endl;
        //Special weighting technique that gives a slight similarity deduction if the search query and the entry have differing sizes. COULD BE IMPLEMENTED LATER
        //THIS WILL CAUSE THE PROGRAM TO FAVOR THINGS OF CLOSER LENGTH TO THE ACTUAL SEARCH QUERY

        tmpRatio = (((float)charactersAlike/stringAnswer.size())*(((float)stringAnswer.size()/tmp2.size())+1)/2);
        if(tmpRatio > 0){
            searchResults.push_back(games.at(x));
            ratioAlike.push_back(tmpRatio);
        }
        cout << tmpRatio << endl;

        tmpWordsInQuery.clear();
        cout << "We now have a ratio of alikeness, we need to organize our results by the highest ratio alike" << endl;
    }
    /*
    Here I will load my ratios and respective strings, which will later be replaced by a specific platform in the real program.
    */
    //Insertion based algorithm
    int j;
    float temp;
    Game tmpGame;
    //Right here, I don't want to change the order of the actual database, so I guess I have to make an entire copy of the database to be used... ORRRRRRRRRR All the datapieces that showed up as a result.
    for (int i = 0; i < ratioAlike.size(); i++){
        j = i;
        while (j > 0 && ratioAlike.at(j) < ratioAlike.at(j-1)){
            temp = ratioAlike.at(j);
            tmpGame = searchResults.at(j);
            ratioAlike.at(j) = ratioAlike.at(j-1);
            searchResults.at(j) = searchResults.at(j-1);
            ratioAlike.at(j-1) = temp;
            searchResults.at(j-1) = tmpGame;
            j--;
        }
    }
    system("cls");
    cout << "GAMES" << endl;
    cout << "NAME" << endl;
    for(int x = ratioAlike.size()-1; x >= 0; x--){
        cout << searchResults.at(x).getName() << endl;
    }
}

Database::~Database()
{
    //dtor
}
