//
// Created by bigbl on 2/1/2022.
//

#include "List.h"


void List::displayAll() {

    Node* current = head;
    for(int i = 0; i <= getListSize() - 1; i++) {
        cout << endl << current->data << endl;
        current = current->next;
    }
}

void List::searchAutoComplete(char ch) {

    Node* current = head;
    searchResults = false;
    for(int i = 0; i < getListSize() - 1; i++) {
        if (current->data.find(input) < current->data.length()) {
            searchResults = true;
            cout << current->data << endl;
        }
        current = current->next;
    }

    if(!searchResults) {
      cout << "Type Y to save this into your list!" << endl;
      if (int(ch) == 121) {
          AppendItem(input);
          cout << "Item Added!!" << endl;
      }
    }
}



/** Getter and Setters for Both the Number of Items
 *  And the values in the array.
 */


int List::getLetterCount() const {
    return letterCount;
}

void List::setLetterCount(int letterCount) {
    List::letterCount = letterCount;
}


/** Load File Helper Method*/

void List::loadFile() {
    ifstream inFile;
    string line;
    inFile.open("C:\\Users\\bigbl\\CLionProjects\\autoComplete\\assests\\scratch.txt"); //Absolute path for now cause im bad.

    /* Check if file is open, then we check if head is nullptr, if its not nullptr then do normal functionality */
    if(inFile.is_open()) {
        while (std::getline(inFile, line)) {
            Node* temp = new Node(line);
            if(head == nullptr) {
                head = temp;
                tail = temp;
                listSize++;
            } else {
                tail->next = temp;
                tail = temp;
                listSize++;
            }
        }
        inFile.close();
    } else {
        cout << "This shit broke";
    }
}

void List::AppendItem(string inputValue) {
    Node* temp = new Node(inputValue);
    if(head == nullptr) {
        head = temp;
        tail = temp;
        listSize++;
    } else {
        tail->next = temp;
        tail = temp;
        listSize++;
    }
    cout << "Your value has been added.";
}


List::Node *List::getHead() const {
    return head;
}

void List::setHead(List::Node *head) {
    List::head = head;
}

List::Node *List::getTail() const {
    return tail;
}

void List::setTail(List::Node *tail) {
    List::tail = tail;
}

int List::getListSize() const {
    return listSize;
}

void List::setListSize(int listSize) {
    List::listSize = listSize;
}


void List::backSpace(char ch) {
    letterCount--;
    if(letterCount< 0) {
        letterCount = 0;
        cout << input;
    }
    input[letterCount] = '\0';
    textcolor(3);
    cout << input;
    if(letterCount > 2) {
        textcolor(3);
        cout << endl << endl <<  "-------SEARCH RESULTS-------: " << endl;
        searchAutoComplete(ch);
    } else {
        displayAll();
    }
}

void List::characterPress(char ch) {
    if (letterCount > 1) {
        textcolor(3);
        input[letterCount] = static_cast<char>(ch);
        input[letterCount + 1] = '\0';
        letterCount++;
        cout << input;
        cout << endl << endl <<  "-------SEARCH RESULTS-------: " << endl;
        searchAutoComplete(ch);
    } else {
        textcolor(2);
        input[letterCount] = static_cast<char>(ch);
        input[letterCount + 1] = '\0';
        letterCount++;
        cout << input;
        displayAll();
    }
}

/** Text Color Method Provided by Christopher**/

void List::textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            color + (__BACKGROUND << 4));
}
