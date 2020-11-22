#include <iostream>

#include "graphics.h"
#include "window.h"

using namespace std;

void Graphics::drawCanvas() {
    // Art translation
    int x = 23, y = 3;

    // ASCII Drawing
    Window window;

    window.textColor(0);

    window.gotoxy(x, y);   cout << "             . . .";
    window.gotoxy(x, y+1); cout << "              \\|/";
    window.gotoxy(x, y+2); cout << "            `--+--'";
    window.gotoxy(x, y+3); cout << "              /|\\";
    window.gotoxy(x, y+4); cout << "             ' | '";
    window.gotoxy(x, y+5); cout << "               |";
    window.gotoxy(x, y+6); cout << "               |";
    window.gotoxy(x, y+7); cout << "           ,--'#`--.";
    window.gotoxy(x, y+8); cout << "           |#######|";
    window.gotoxy(x, y+9); cout << "        _.-'#######`-._";
    window.gotoxy(x, y+10);cout << "     ,-'###############`-.";
    window.gotoxy(x, y+11);cout << "   ,'#####################`,";
    window.gotoxy(x, y+12);cout << "  /#########################\\";
    window.gotoxy(x, y+13);cout << " |###########################|";
    window.gotoxy(x, y+14);cout << "|#############################|";
    window.gotoxy(x, y+15);cout << "|#############################|";
    window.gotoxy(x, y+16);cout << "|#############################|";
    window.gotoxy(x, y+17);cout << "|#############################|";
    window.gotoxy(x, y+18);cout << " |###########################|";
    window.gotoxy(x, y+19);cout << "  \\#########################/";
    window.gotoxy(x, y+20);cout << "   `.#####################,'";
    window.gotoxy(x, y+21);cout << "     `._###############_,'";
    window.gotoxy(x, y+22);cout << "        `--..#####..--'";
}

void Graphics::drawMenu() {
    // Menu translation
    int x = 5, y = 3;
    int width = 18;
    int height = 4;

    // Bomb art
    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<6; i++) printf("%c", 205);
    printf(" Menu ");
    for(int i=12; i<width; i++) printf("%c", 205);
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
