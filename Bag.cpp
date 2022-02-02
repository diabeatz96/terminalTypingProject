//
// Created by bigbl on 2/1/2022.
//

#include "Bag.h"


void Bag::displayAll() {
    cout << endl << endl;
    for(int i = 0; i <= animeList.size() - 1; i++) {
        cout << endl << animeList[i] << endl;
    }
}

void Bag::searchAutoComplete() {

    cout << endl;

    for(int i = 0; i < animeList.size() - 1; i++) {
        if (animeList[i].find(input) < animeList[i].length()) {
            cout << animeList[i] << endl;
        }
    }
}



/** Getter and Setters for Both the Number of Items
 *  And the values in the array.
 */

int Bag::getNumOfItems() const {
    return numOfItems;
}

void Bag::setNumOfItems(int numOfItems) {
    Bag::numOfItems = numOfItems;
}

const vector<string> &Bag::getAnimeList() const {
    return animeList;
}

void Bag::setAnimeList(const vector<string> &animeList) {
    Bag::animeList = animeList;
}

int Bag::getLetterCount() const {
    return letterCount;
}

void Bag::setLetterCount(int letterCount) {
    Bag::letterCount = letterCount;
}


/** Load File Helper Method*/

void Bag::loadFile() {
    ifstream inFile;
    string line;
    inFile.open("C:\\Users\\Adam\\CLionProjects\\autoComplete\\assests\\scratch.txt"); //Absolute path for now cause im bad.

    /* Check if file is open, if it isn't we are going to push a value into animelist in the vector */
    if(inFile.is_open()) {
        while (std::getline(inFile, line)) {
            animeList.push_back(line);
        }
        inFile.close();
    } else {
        cout << "This shit broke";
    }
}

