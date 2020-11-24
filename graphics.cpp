#include <iostream>

#include "graphics.h"
#include "window.h"

using namespace std;

// Design

void Graphics::drawBombCanvas() {
    // Art anchor
    int x = 23, y = 2;

    // ASCII Drawing
    Window window;

    window.textColor(0);

    window.gotoxy(x, y);   cout << "              . . .";
    window.gotoxy(x, y+1); cout << "               \\|/";
    window.gotoxy(x, y+2); cout << "             '--+--'";
    window.gotoxy(x, y+3); cout << "               /|\\";
    window.gotoxy(x, y+4); cout << "              ' | '";
    window.gotoxy(x, y+5); cout << "                |";
    window.gotoxy(x, y+6); cout << "                |";
    window.gotoxy(x, y+7); cout << "           ,--'###`--.";
    window.gotoxy(x, y+8); cout << "           |#########|";
    window.gotoxy(x, y+9); cout << "        _.-'#########`-._";
    window.gotoxy(x, y+10);cout << "     ,-'#################`-.";
    window.gotoxy(x, y+11);cout << "   ,'#######################`,";
    window.gotoxy(x, y+12);cout << "  /###########################\\";
    window.gotoxy(x, y+13);cout << " |#############################|";
    window.gotoxy(x, y+14);cout << "|###############################|";
    window.gotoxy(x, y+15);cout << "|###############################|";
    window.gotoxy(x, y+16);cout << "|###############################|";
    window.gotoxy(x, y+17);cout << "|###############################|";
    window.gotoxy(x, y+18);cout << "|###############################|";
    window.gotoxy(x, y+19);cout << "|###############################|";
    window.gotoxy(x, y+20);cout << " |#############################|";
    window.gotoxy(x, y+21);cout << "  \\###########################/";
    window.gotoxy(x, y+22);cout << "   `.#######################,'";
    window.gotoxy(x, y+23);cout << "     `._#################_,'";
    window.gotoxy(x, y+24);cout << "        `--..#######..--'";
}

void Graphics::drawGameBox(int field[10][10]) {
//    for(int i=0; i<10; i++) {
//        for(int j=0; j<10; j++) {
//            printf("%d ", field[i][j]);
//        }
//        printf("\n");
//    }

    // Box anchor
    int x = 29, y = 13;
    int width = 19, height = 10;

    // Box maker

    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<width; i++) printf("%c", 205);
    printf("%c", 187);

    int val, mchar;

    for(int i=1; i<=height; i++) {
        window.gotoxy(x, y+i);printf("%c", 186);
        window.gotoxy(x+width+1, y+i);printf("%c", 186);

        for(int j=0; j<18; j+=2) {
            val = field[i-1][j/2];
            mchar = (val == 0) ? 254 : (val == -1) ? 64 : (val == -2) ? 33 : 48+val;

            window.gotoxy(x+1+j, y+i);printf("%c ", mchar);
        }
        val = field[i-1][9];
        mchar = (val == 0) ? 254 : (val == -1) ? 64 : (val == -2) ? 33 : 48+val;

        window.gotoxy(x+19, y+i);printf("%c", mchar);
    }

    window.gotoxy(x,y+height+1);
    printf("%c", 200);
    for(int i=0; i<width; i++) printf("%c", 205);
    printf("%c", 188);
}

// Interface

void Graphics::drawMainMenu() {
    // Menu anchor
    int x = 5, y = 3;
    int width = 14, height = 4;

    // Bomb art
    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<4; i++) printf("%c", 205);
    printf(" Menu ");
    for(int i=10; i<width; i++) printf("%c", 205);
    printf("%c", 187);

    for(int i=1; i<=height; i++) {
        window.gotoxy(x, y+i);printf("%c", 186);
        window.gotoxy(x+width+1, y+i);printf("%c", 186);
    }

    window.gotoxy(x,y+height+1);
    printf("%c", 200);
    for(int i=0; i<width; i++) printf("%c", 205);
    printf("%c", 188);
}

void Graphics::clearMainMenu() {
    int x = 6, y = 3;
    int width = 14, height = 5;

    Window window;

    window.textColor(0);

    window.gotoxy(x, y);
    for(int i=0; i<width; i++) printf("%c", 205);

    for(int i=1; i<height; i++) {
        window.gotoxy(x, y+i);
        for(int j=0; j<width; j++) {
            printf(" ");
        }
    }
}

// Gameplay

void Graphics::writeSelection(int val, bool isCol) {
    int x = 6, y = 4;

    string text[] = {"linha ", "coluna "};

    Window window;
    window.textColor(0);

    window.gotoxy(x, y);cout << "  Selecionar";
    window.gotoxy(x, y+1);cout << text[isCol];
    printf("(%d) do", val);
    if (val < 10) printf(" ");
    window.gotoxy(x, y+2);cout << "mkampo minado?";
    window.gotoxy(x, y+3);cout << "   <Enter>";
}
