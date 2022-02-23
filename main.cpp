#include <iostream>
#include "List.h"
#include <conio.h>


int main() {

    bool gameOver = false;
    List newList;
    newList.loadFile();


        char ch;

        while(!gameOver){

            if(_kbhit()) {
                system("cls");
                newList.textcolor(5);
                std::cout << R"(

                 _                   _____                     _
     /\         (_)                 / ____|                   | |
    /  \   _ __  _ _ __ ___   ___  | (___   ___  __ _ _ __ ___| |__
   / /\ \ | '_ \| | '_ ` _ \ / _ \  \___ \ / _ \/ _` | '__/ __| '_ \
  / ____ \| | | | | | | | | |  __/  ____) |  __/ (_| | | | (__| | | |
 /_/    \_\_| |_|_|_| |_| |_|\___| |_____/ \___|\__,_|_|  \___|_| |_|



)" << '\n';
                ch = getch();
                if (int(ch) == 27) {
                    break;
                }
                if (int(ch) == 8) {
                newList.backSpace(ch);
                } else {
                    newList.characterPress(ch);
                }
            }
        }




}