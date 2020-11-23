#include <iostream>
#include <conio.h>

#include "menu.h"
#include "window.h"
#include "graphics.h"

using namespace std;

// Main

int Menu::showMainMenu() {
    // Menu parameters
    string opt[] = {"Jogar", "Tutorial", "Sobre", "Sair"};

    int x = 7, y = 4;
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


// Game

int Menu::rowSelection() {
    Graphics graphics;

    graphics.clearMainMenu();
    graphics.writeSelection(1, false);

    int x = 29, y = 14;
    int color = 14;

    int count = 10;

    // Matrix coloring

    Window window;

    window.textColor(color);
    for(int j=0; j<18; j+=2) {
        window.gotoxy(x+1+j, y);printf("%c ", 254);
    }
    window.gotoxy(x+19, y);printf("%c", 254);

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

        window.textColor(color);
        for(int j=0; j<18; j+=2) {
            window.gotoxy(x+1+j, y+diff);printf("%c ", 254);
        }
        window.gotoxy(x+19, y+diff);printf("%c", 254);

        window.textColor(0);
        for(int j=0; j<18; j+=2) {
            window.gotoxy(x+1+j, y+bef);printf("%c ", 254);
            window.gotoxy(x+1+j, y+next);printf("%c ", 254);
        }
        window.gotoxy(x+19, y+bef);printf("%c", 254);
        window.gotoxy(x+19, y+next);printf("%c", 254);

        graphics.writeSelection(diff+1, false);
    }

    return auxY-y;
}

int Menu::columnSelection(int row) {
    Graphics graphics;

    graphics.clearMainMenu();
    graphics.writeSelection(1, true);

    int x = 30, y = 14;
    int c0 = 14, c1 = 13;

    int count = 20;

    // Matrix coloring

    Window window;

    window.textColor(c0);
    for(int i=0; i<10; i++) {
        window.gotoxy(x, y+i);printf("%c", 254);
    }

    // Arrow movement

    char key;

    int auxX = x;
    int maxX = x + count - 2;

    while((key = getch()) != 13) {
        // Moving the arrow
        if(key == 75 && auxX == x) { // Left limit
            auxX = maxX;
        }
        else if(key == 75 && auxX > x) { // Going left
            auxX-=2;
        }
        else if(key == 77 && auxX < maxX) { // Going right
            auxX+=2;
        }
        else if(key == 77 && auxX == maxX) { // Right limit
            auxX = x;
        }

        // Fixing the text color
        int diff = auxX - x;
        int bef = (diff - 2 >= 0) ? diff-2 : maxX-x;
        int next = (diff + 2 < count) ? diff+2 : 0;

        window.textColor(0);
        for(int i=0; i<10; i++) {
            window.gotoxy(x+bef, y+i);printf("%c", 254);
            window.gotoxy(x+next, y+i);printf("%c", 254);
        }

        window.textColor(c0);
        for(int i=0; i<10; i++) {
            window.gotoxy(x+diff, y+i);printf("%c", 254);
        }

        // Restore selected row
        window.gotoxy(x+bef, y+row);printf("%c", 254);
        window.gotoxy(x+next, y+row);printf("%c", 254);

        graphics.writeSelection(diff+1, false);
    }

    return auxX-x;
}
