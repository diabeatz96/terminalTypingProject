#include <iostream>
#include <raylib.h>
#include "Bag.h"
#include <conio.h>


int main() {

    bool gameOver = false;
    Bag newBag;
    newBag.loadFile();


        char ch;

        while(!gameOver){
            if(_kbhit()) {
                system("cls");
                ch = getch();
                if (int(ch) == 27) {
                    break;
                }
                if (int(ch) == 8) {
                    newBag.letterCount--;
                    if(newBag.letterCount< 0) {
                        newBag.letterCount = 0;
                        cout << newBag.input;
                    }
                    newBag.input[newBag.letterCount] = '\0';
                    cout << newBag.input;
                    if(newBag.letterCount > 2) {
                        newBag.searchAutoComplete();
                    } else {
                        newBag.displayAll();
                    }
                } else {
                    if(newBag.letterCount > 1) {
                        newBag.input[newBag.letterCount] = static_cast<char>(ch);
                        newBag.input[newBag.letterCount + 1] = '\0';
                        newBag.letterCount++;
                        cout << newBag.input;
                        newBag.searchAutoComplete();
                    } else {
                        newBag.input[newBag.letterCount] = static_cast<char>(ch);
                        newBag.input[newBag.letterCount + 1] = '\0';
                        newBag.letterCount++;
                        cout << newBag.input;
                        newBag.displayAll();
                    }
                }
            }

        }
    }