//
// Created by bigbl on 2/1/2022.
//

#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "raylib.h"

#ifndef commandLineHWVersion_BAG_H
#define commandLineHWVersion_BAG_H

using namespace std;
const int MAX_INPUT = 20;

class Bag {

public:
    int numOfItems;
    char input[MAX_INPUT + 1] = "\0";
    int letterCount = 0;

    int getLetterCount() const;

    void setLetterCount(int letterCount);

    // Vector method best way. Can use Static if we really about that life.
    vector<string> animeList;

    /* Getters and Setters for Function Calls*/
    int getNumOfItems() const;

    void setNumOfItems(int numOfItems);

    const vector<string> &getAnimeList() const;

    void setAnimeList(const vector<string> &animeList);

    /** Function to define current value in array */
    void displayAll();
    void searchAutoComplete();
    void loadFile();

};


#endif //commandLineHWVersion_BAG_H
