#include "Database.h"


Database::Database()
{
    //ctor
}

vector<vector<Platform*>> Database::getDatabase(){

    return this->database;

}

void Database::setDatabase(vector<vector<Platform*>> tmp){
    this->database = tmp;
}
vector<string> Database::getCategoriesInUse(){
    return this->categoriesInUse;
}

void Database::setPossibleCategories(vector<string> tmp){
    this->possibleCategories= tmp;
}

vector<string> Database::getPossibleCategories(){
    return this->possibleCategories;
}

void Database::setCategoriesInUse(vector<string> tmp){
    this->categoriesInUse= tmp;
}
/*
void Database::chooseData(vector<vector<*Platform>> tmpDatabase){
    for(int x = 0; x < tmpDatabase.size(); x++){
        if(categoriesInUse.at(x)== "Games"){
            cout << "GAMES" << endl;
            cout << "Name" << "       Console" << endl;
        }else if(categoriesInUse.at(x) == "Books"){
            cout << "BOOKS" << endl;
            cout << "Name" << "       Total Pages" << endl;
        }
        platforms = tmpDatabase.at(x);
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

*/

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




void Database::addEntry(vector<string> entryData)
{
    system("cls");
    stringstream ss(entryData.at(0));
    int intAnswer;
    ss >> intAnswer;
    if(categoriesInUse.at(intAnswer)== "Games"){
        Game tmp;
        tmp.setName(entryData.at(1));
        tmp.setConsole(entryData.at(2));
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
        Book tmp;
        tmp.setName(entryData.at(1));
        int tmpInt;
        stringstream sss(entryData.at(2));
        sss >> tmpInt;
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

void Database::deleteEntry(int index, vector<vector<Platform*>> tmp)
{
    //lets say index =2
    vector<string> tmpEntryData;
    vector<string> comparingData;
    int category = 0;
    bool found = false;
    while(category<tmp.size()&&found == false){
        platforms = tmp.at(category);
        cout << "PLATFORM LOADED INTO CATEGORY " << category << endl;
        for(int c = 0; c < platforms.size(); c++){
            if(index != 1){
                index--;
            }else{
                tmpEntryData = platforms.at(c)->printData();
                cout << "DISPLAYING USER'S REQUESTED DELETE" << endl;
                for(int g = 0; g < tmpEntryData.size(); g++){
                    cout << tmpEntryData.at(g) << "    ";
                }
                found = true;
                break;
                cout << endl;
            }
        }
        cout << "It was not found in category " << category << endl;
        category++;
        cout << category << endl;
    }
    //Now we should have the platform of the item that the user wants to delete and the data of the entry.
    //We compare the entry to everything inside of the platform that sits in the main database.
    //Optimization: Alphabetical order will allow for increased speed when comparing.
    category--;
    int thingsAlike = 0;
    platforms=this->database.at(category);
    for(int x = 0; x < platforms.size(); x++){
        comparingData = platforms.at(x)->printData();
        cout << comparingData.at(0);
    }
    bool deleted = false;
    for(int x = 0; x < platforms.size(); x++){
        comparingData = platforms.at(x)->printData();
        for(int c = 0 ; c < comparingData.size(); c++){
            if(comparingData.at(c) == tmpEntryData.at(c)){
                thingsAlike++;
            }else{
                break;
            }
            if(thingsAlike==comparingData.size()){
                cout << "MATCH IS FOUND" << endl;
                cout << "DELETING" << comparingData.at(0) << endl;
                if(categoriesInUse.at(category)== "Books"){
                    books.erase(books.begin()+x);
                    platforms.clear();
                    deleted = true;
                    for(int t = 0; t < books.size(); t++){
                        platforms.push_back(&books.at(t));
                    }
                }else if(categoriesInUse.at(category) == "Games"){
                    games.erase(games.begin()+x);
                    platforms.clear();
                    deleted = true;
                    for(int t = 0; t < games.size(); t++){
                        platforms.push_back(&games.at(t));
                    }
                }
            }
        }
        if(deleted == true){
            break;
        }
    }
    this->database.at(category) = platforms;
}

vector<vector<Platform*>> Database::searchEntry(string tmpAnswer)
{
    //ADD MULTIPLE DIFFERENT TYPES OF PLATFORMS LIKE BOOKS BY USING SOME EQUIVALENT TO vector<vector<*platforms>> or something of the similar
    /**
    Unfortunatly, this will be an absolute mess, because i'm looking for through hard coded lists, therefore i'll have to loop around for each platform... Games, Books, ETC..
    **/

    string stringAnswer;
    stringAnswer = tmpAnswer;
    float tmpRatio;
    string tmp = "";
    vector<string> wordsInSearchQuery;
    vector<vector<Platform*>> searchResults;
    transform(stringAnswer.begin(), stringAnswer.end(), stringAnswer.begin(), ::toupper);
    //tmp2 is a replacement for games.at(x).getName(). I was getting a fpermissive error because i had it going to games.at(x).getName().at(n)
    //WTF I GOT RID OF THE WHOLE SECTION.
    for(int t = 0; t < stringAnswer.size(); t++){
        if(stringAnswer.at(t)!= ' '){
            if(tmp.size()== 0){
                tmp = stringAnswer.at(t);
            }else{
                tmp += stringAnswer.at(t);
            }
            }else{
                cout << "NEW ONE FOUND" << endl;
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
    return searchResults;
}

Database::~Database()
{
    //dtor
}
