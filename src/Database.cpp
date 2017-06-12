#include "Database.h"


Database::Database()
{
    //ctor
}

void Database::displayData()
{
    //GAME DISPLAY
    vector<string> tmp;
    for(int x = 0; x < database.size(); x++){
        if(categoriesInUse.at(x)== "Games"){
            cout << "GAMES" << endl;
            cout << "Name" << "       Console" << endl;
        }else if(categoriesInUse.at(x) == "Books"){
            cout << "BOOKS" << endl;
            cout << "Name" << "       Total Pages" << endl;
        }
        platforms = database.at(x);
        for(int c = 0; c < platforms.size(); c++){
            tmp = platforms.at(c)->printData();
            for(int j = 0; j < tmp.size(); j++){
                cout << tmp.at(j) << "    ";
            }
            cout << endl;
        }
    }
}



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
            cout << "You have decided to add a game platform" << endl;
            database.push_back(tmpPlatform);
            auto it = find(possibleCategories.begin(), possibleCategories.end(), "Games");
            if(it != possibleCategories.end()){
                possibleCategories.erase(it);
                categoriesInUse.push_back("Games");
            }else{
                cout << "ERRRROROROROROROR" << endl;
            }
        }else if(stringAnswer == "BOOKS"){
            cout << "You have decided to add a book platform" << endl;
            database.push_back(tmpPlatform);
            auto it = find(possibleCategories.begin(), possibleCategories.end(), "Books");
            if(it!=possibleCategories.end()){
                possibleCategories.erase(it);
                categoriesInUse.push_back("Books");
            }else{
                cout << "ERROROROROROROR" << endl;
            }
        }
    }
}




void Database::addEntry()
{
    system("cls");
    cout << "You are adding a entry" << endl;
    cout << "What category will your entry be in?" << endl;
    for(int x = 0; x < categoriesInUse.size(); x++){
        cout << x << ": " << categoriesInUse.at(x) << endl;
    }
    int intAnswer;
    cin >> intAnswer;
    if(categoriesInUse.at(intAnswer)== "Games"){
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
        platforms.clear();
        for(int x = 0; x < games.size(); x++){
            platforms.push_back(&games.at(x));
        }
        cout << "Platforms is now size " << platforms.size() << endl;
        database.at(intAnswer) = platforms;
        cout << "database loaded is now " << database.at(intAnswer).size() << endl;
        platforms.clear();

    }else if(categoriesInUse.at(intAnswer) == "Books"){
        cout << "You have chosen to add a new book" << endl;
        Book tmp;
        cout << "What is the name of the book?" << endl;
        string stringAnswer;
        cin.ignore();
        getline(cin , stringAnswer);
        tmp.setName(stringAnswer);
        cout << "What is the total page number of the book" << endl;
        int tmpInt;
        cin >> tmpInt;
        tmp.setPage(tmpInt);
        books.push_back(tmp);
        cout << "You have created a new game entry with the name " << tmp.getName() << " thats has this many pages: " << tmp.getPage() << endl;
        platforms.clear();
        for(int x = 0; x < books.size(); x++){
            platforms.push_back(&books.at(x));
        }
        database.at(intAnswer) = platforms;
        platforms.clear();
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
    vector<vector<Platform*>> searchResults;
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

    vector<vector<float>> ratioAlike;
    vector<float> tmpfloat;
    vector<string> tmp2;
    vector <string> tmpWordsInQuery;
    /**
    OH GOD THE HUMANITY
    **/
    for(int j = 0; j < database.size(); j++){
        platforms.clear();
        tmp.clear();
        searchResults.push_back(platforms);
        ratioAlike.push_back(tmpfloat);
        platforms = database.at(j);
        for(int x = 0; x < platforms.size(); x++){
            tmp2 = platforms.at(x)->printData();
            transform(tmp2.at(0).begin(), tmp2.at(0).end(), tmp2.at(0).begin(), ::toupper);
            for(int n = 0; n < tmp2.at(0).size(); n++){
                if(tmp2.at(0).at(n) != ' '){
                    if(tmp.size()== 0){
                        tmp = tmp2.at(0).at(n);
                    }else{
                        tmp += tmp2.at(0).at(n);
                    }
                }else{
                    tmpWordsInQuery.push_back(tmp);
                    tmp = "";
                }
            }
            tmpWordsInQuery.push_back(tmp);
            tmp = "";
            cout << "There are " << tmpWordsInQuery.size() << " words inside of " << tmp2.at(0) << endl;

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
            cout << "There were " << charactersAlike << " characters alike between " << stringAnswer << " and " << tmp2.at(0) << endl << endl;
            cout << endl;
            //Special weighting technique that gives a slight similarity deduction if the search query and the entry have differing sizes. COULD BE IMPLEMENTED LATER
            //THIS WILL CAUSE THE PROGRAM TO FAVOR THINGS OF CLOSER LENGTH TO THE ACTUAL SEARCH QUERY

            tmpRatio = (((float)charactersAlike/stringAnswer.size())*(((float)charactersAlike/tmp2.at(0).size())+1)/2);
            //RIGHT HERE I NEED TO FIGURE EFFECTIVELY PUSH BACK THE PLATFORM PIECES, THIS PIECE WOULD HAVE ME PUSH BACK CERTAIN OTHER PIECES.
            if(tmpRatio > 0){
                searchResults.at(j).push_back(platforms.at(x));
                ratioAlike.at(j).push_back(tmpRatio);
            }
            cout << tmpRatio << endl;

            tmpWordsInQuery.clear();
            cout << "We now have a ratio of alikeness, we need to organize our results by the highest ratio alike" << endl;
        }
    }
    /*
    Here I will load my ratios and respective strings, which will later be replaced by a specific platform in the real program.
    */
    //Insertion based algorithm
    int j;
    float temp;
    Platform* tmpPlatform;
    //I have to make a new nested organization algorithm.
    for(int t = 0; t < ratioAlike.size(); t++){
        platforms = searchResults.at(t);
        tmpfloat = ratioAlike.at(t);
        for (int i = 0; i < tmpfloat.size(); i++){
            j = i;
            tmp2 = platforms.at(i)->printData();
            cout << tmp2.at(0) << " " << tmpfloat.at(i) << endl;
            while (j > 0 && tmpfloat.at(j) < tmpfloat.at(j-1)){
                //This is a test to see if it works.
                temp = tmpfloat.at(j);
                tmpPlatform = platforms.at(j);
                tmpfloat.at(j) = tmpfloat.at(j-1);
                platforms.at(j) = platforms.at(j-1);
                tmpfloat.at(j-1) = temp;
                platforms.at(j-1) = tmpPlatform;
                j--;
            }
            ratioAlike.at(t) = tmpfloat;
            searchResults.at(t) = platforms;
        }
    }
    for(int x = 0; x < searchResults.size(); x++){
        if(categoriesInUse.at(x)== "Games"){
            cout << "GAMES" << endl;
            cout << "Name" << "       Console" << endl;
        }else if(categoriesInUse.at(x) == "Books"){
            cout << "BOOKS" << endl;
            cout << "Name" << "       Total Pages" << endl;
        }
        platforms = searchResults.at(x);
        if(platforms.size()==0){
            cout <<"NO DATA FOUND" << endl;
        }else{
            for(int c = platforms.size()-1 ; c >= 0; c--){
                tmp2 = platforms.at(c)->printData();
                for(int j = 0; j < tmp2.size(); j++){
                    cout << tmp2.at(j) << "    ";
                }
                cout << endl;
            }
        }
        cout << endl << endl;
    }
}

Database::~Database()
{
    //dtor
}
