//
// Created by bigbl on 2/1/2022.
//

#include <utility>

#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "windows.h"
#include "conio.h"

#ifndef TESTPROJECT_BAG_H
#define TESTPROJECT_BAG_H

using namespace std;
const int MAX_INPUT = 20;

class List {

public:
    struct Node {
        string data;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(string inputData) {
            data = std::move(inputData);
        }
    };


    Node* head = nullptr;
    Node* tail = nullptr;
    int listSize = 0;

    Node *getHead() const;

    void setHead(Node *head);

    Node *getTail() const;

    void setTail(Node *tail);

    int getListSize() const;

    void setListSize(int listSize);

    // Work involving the letters inputs etc.
    char input[MAX_INPUT + 1] = "\0";
    int letterCount = 0;
    bool searchResults = true;

    int getLetterCount() const;
    void setLetterCount(int letterCount);

    // Vector method best way. Can use Static if we really about that life.

    /* Getters and Setters for Function Calls*/

    /** Function to define current value in array */
    void displayAll();
    void searchAutoComplete(char ch);
    void loadFile();
    void AppendItem(string value);

    void backSpace(char ch);

    void characterPress(char ch);

    void textcolor(int color);

};


#endif //TESTPROJECT_BAG_H
