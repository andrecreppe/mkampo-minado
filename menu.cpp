#include <iostream>
#include <conio.h>

#include "menu.h"
#include "window.h"

using namespace std;

int Menu::showMenu() {
    // Menu parameters
    string opt[] = {"Primeira opcao", "Segunda opcao", "Terceira opcao", "Sair"};

    int x = 10, y = 10;
    int c0 = 0, c1 = 14, c2 = 12;

    // Menu options display

    Window window;

    int count = sizeof(opt)/sizeof(opt[0]);

    window.textColor(c1);
    window.gotoxy(x, y); cout << "-> " << opt[0];

    window.textColor(c0);
    for(int i=1; i<count; i++) {
        window.gotoxy(x+3, y+i); cout << opt[i];
    }

    // Arrow movement

    char key;

    int auxY = y;
    int maxY = y + count - 1;

    while((key = getch()) != 13) {
        // Moving the arrow
        if(key == 72 && auxY == y) { // Upper limit
            auxY = maxY;
        }
        else if(key == 72 && auxY > y) { // Going up
            auxY--;
        }
        else if(key == 80 && auxY < maxY) { // Going down
            auxY++;
        }
        else if(key == 80 && auxY == maxY) { // Inferior limit
            auxY = y;
        }

        // Fixing the text color
        int diff = auxY - y;
        int bef = (diff - 1 >= 0) ? diff-1 : maxY-y;
        int next = (diff + 1 < count) ? diff+1 : 0;

        (diff < (count - 1)) ? window.textColor(c1) : window.textColor(c2); // Special color (c2)
        window.gotoxy(x, y+diff);cout << "-> " << opt[diff];

        window.textColor(c0);
        window.gotoxy(x, y+bef);cout << "   " << opt[bef];
        window.gotoxy(x, y+next);cout << "   " << opt[next];
    }

    return auxY - y;
}
