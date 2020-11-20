#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "menu.h"
#include "window.h"

using namespace std;

void Menu::showMenu() {
    Window window;

    string opt[] = {"Primeira opcao", "Segunda opcao", "Terceira opcao", "Sair"};

    int x = 10;
    int y = 10, auxY = y;
    int c1 = 14;
    int c2 = 12;

    window.gotoxy(x+3, y); cout << opt[0];
    window.gotoxy(x+3, y+1); cout << opt[1];
    window.gotoxy(x+3, y+2); cout << opt[2];
    window.gotoxy(x+3, y+3); cout << opt[3];

    window.textColor(14);
    window.gotoxy(x, y);printf("-> ");

    char key;
    int diff;

    do {
        // Moving the arrow
        if(key == 72 && auxY == 10) { // Upper limit
            auxY = 13;
        }
        else if(key == 72 && auxY > 10) { // Going up
            auxY--;
        }
        else if(key == 80 && auxY < 13) { // Going down
            auxY++;
        }
        else if(key == 80 && auxY == 13) { // Inferior limit
            auxY = 10;
        }

        if(key == 80 || key == 72) {
            window.textColor(c1);

            for(int i=10; i<14; i++) {
                window.gotoxy(x, i);printf("   ");
                window.gotoxy(x, auxY);printf("-> ");
            }
        }

//        diff = auxY - y;
//        int count = 3; // (total - 1)
//
//        if(diff != count) {
//            window.textColor(c1);
//            window.gotoxy(x+3, y+diff);cout << opt[diff];
//
//            window.textColor(0);
//            window.gotoxy(x+3, y+diff+1);cout << opt[diff+1];
//            window.gotoxy(x+3, y+3);cout << opt[diff+3];
//        }
//
//        else {
//            window.textColor(c2);
//            window.gotoxy(x+3, y+3);cout << opt[3];
//            window.gotoxy(x, y+3);printf("-> ");
//
//            window.textColor(0);
//            window.gotoxy(x+3, y);cout << opt[0];
//            window.gotoxy(x+3, y+2);cout << opt[2];
//        }

        // Fixing colors
        window.textColor(c1);
        if(auxY == 10) {
            window.gotoxy(x+3, y);cout << opt[0];

            window.textColor(0);
            window.gotoxy(x+3, y+1);cout << opt[1];
            window.gotoxy(x+3, y+3);cout << opt[3];
        } else if(auxY == 11) {
            window.gotoxy(x+3, y+1);cout << opt[1];

            window.textColor(0);
            window.gotoxy(x+3, y);cout << opt[0];
            window.gotoxy(x+3, y+2);cout << opt[2];
        } else if(auxY == 12) {
            window.gotoxy(x+3, y+2);cout << opt[2];

            window.textColor(0);
            window.gotoxy(x+3, y+1);cout << opt[1];
            window.gotoxy(x+3, y+3);cout << opt[3];
        } else if(auxY == 13) {
            window.textColor(c2);
            window.gotoxy(x+3, y+3);cout << opt[3];
            window.gotoxy(x, y+3);printf("-> ");

            window.textColor(0);
            window.gotoxy(x+3, y);cout << opt[0];
            window.gotoxy(x+3, y+2);cout << opt[2];
        }
    } while((key = getch()) != 13);

//    return auxY - y;
}
