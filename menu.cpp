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
        } else if(key == 72 && auxY > y) { // Going up
            auxY--;
        } else if(key == 80 && auxY < maxY) { // Going down
            auxY++;
        } else if(key == 80 && auxY == maxY) { // Inferior limit
            auxY = y;
        } else {
            continue;
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

int Menu::rowSelection(int field[10][10]) {
    Graphics graphics;

    graphics.writeSelection(1, false);

    int x = 29, y = 14;
    int color = 14;

    int count = 10;

    // Matrix coloring

    Window window;

    int val, mchar;

    window.textColor(color);
    for(int j=0; j<18; j+=2) {
        val = field[0][j/2];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x+1+j, y);printf("%c ", mchar);
    }
    val = field[0][9];
    mchar = graphics.getFieldChar(val);

    window.gotoxy(x+19, y);printf("%c", mchar);

    // Arrow movement

    char key;

    int auxY = y;
    int maxY = y + count - 1;

    while((key = getch()) != 13) {
        // Moving the arrow
        if(key == 72 && auxY == y) { // Upper limit
            auxY = maxY;
        } else if(key == 72 && auxY > y) { // Going up
            auxY--;
        } else if(key == 80 && auxY < maxY) { // Going down
            auxY++;
        } else if(key == 80 && auxY == maxY) { // Inferior limit
            auxY = y;
        } else {
            continue;
        }

        // Fixing the text color
        int diff = auxY - y;
        int bef = (diff - 1 >= 0) ? diff-1 : maxY-y;
        int next = (diff + 1 < count) ? diff+1 : 0;

        window.textColor(color);
        for(int j=0; j<18; j+=2) {
            val = field[diff][j/2];
            mchar = graphics.getFieldChar(val);

            window.gotoxy(x+1+j, y+diff);printf("%c ", mchar);
        }
        val = field[diff][9];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x+19, y+diff);printf("%c", mchar);

        window.textColor(0);
        for(int j=0; j<18; j+=2) {
            val = field[bef][j/2];
            mchar = graphics.getFieldChar(val);

            window.gotoxy(x+1+j, y+bef);printf("%c ", mchar);

            val = field[next][j/2];
            mchar = graphics.getFieldChar(val);

            window.gotoxy(x+1+j, y+next);printf("%c ", mchar);
        }
        val = field[bef][9];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x+19, y+bef);printf("%c", mchar);

        val = field[next][9];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x+19, y+next);printf("%c", mchar);

        graphics.writeSelection(diff+1, false);
    }

    return auxY-y;
}

int Menu::columnSelection(int row, int field[10][10]) {
    Graphics graphics;

    graphics.writeSelection(1, true);

    int x = 30, y = 14;
    int color = 14;

    int count = 20;

    // Matrix coloring

    Window window;

    int val, mchar;

    window.textColor(color);
    for(int i=0; i<10; i++) {
        val = field[i][0];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x, y+i);printf("%c", mchar);
    }

    // Arrow movement

    char key;

    int auxX = x;
    int maxX = x + count - 2;

    int matBef = 9;
    int matNext = 1;

    while((key = getch()) != 13) {
        // Moving the arrow
        if(key == 75 && auxX == x) { // Left limit
            auxX = maxX;
            matBef = 8;
            matNext = 0;
        } else if(key == 75 && auxX > x) { // Going left
            auxX-=2;
            matBef--;
            matNext--;
        } else if(key == 77 && auxX < maxX) { // Going right
            auxX+=2;
            matBef++;
            matNext++;
        } else if(key == 77 && auxX == maxX) { // Right limit
            auxX = x;
            matBef = 9;
            matNext = 1;
        } else {
            continue;
        }

        if(key == 75) {
            matBef = (matBef < 0) ? 9 : matBef;
            matNext = (matNext < 0) ? 9 : matNext;
        } else {
            matBef = (matBef > 9) ? 0 : matBef;
            matNext = (matNext > 9) ? 0 : matNext;
        }

        // Fixing the text color
        int diff = auxX - x;
        int bef = (diff - 2 >= 0) ? diff-2 : maxX-x;
        int next = (diff + 2 < count) ? diff+2 : 0;

        window.textColor(0);
        for(int i=0; i<10; i++) {
            val = field[i][matBef];
            mchar = graphics.getFieldChar(val);

            window.gotoxy(x+bef, y+i);printf("%c", mchar);

            val = field[i][matNext];
            mchar = graphics.getFieldChar(val);

            window.gotoxy(x+next, y+i);printf("%c", mchar);
        }

        window.textColor(color);
        for(int i=0; i<10; i++) {
            val = field[i][diff/2];
            mchar = graphics.getFieldChar(val);

            window.gotoxy(x+diff, y+i);printf("%c", mchar);
        }

        // Restore selected row
        val = field[row][matBef];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x+bef, y+row);printf("%c", mchar);

        val = field[row][matNext];
        mchar = graphics.getFieldChar(val);

        window.gotoxy(x+next, y+row);printf("%c", mchar);

        int decimal = (diff+2)/2;
        graphics.writeSelection(decimal, true);
    }

    return (auxX-x)/2;
}

int Menu::cellOperation() {
    // Menu parameters
    string opt[] = {"Pisar", "Marcar", "Cancelar"};

    int x = 7, y = 5;
    int c0 = 0, c1 = 14, c2 = 12;

    // Menu options display

    Window window;
    Graphics graphics;

    graphics.clearMainMenu();

    window.textColor(0);
    window.gotoxy(x,y-2);cout << " Atividades ";

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
        } else if(key == 72 && auxY > y) { // Going up
            auxY--;
        } else if(key == 80 && auxY < maxY) { // Going down
            auxY++;
        } else if(key == 80 && auxY == maxY) { // Inferior limit
            auxY = y;
        } else {
            continue;
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
