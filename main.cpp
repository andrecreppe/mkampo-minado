#include <iostream>
#include <conio.h>

#include "menu.h"
#include "window.h"
#include "graphics.h"

using namespace std;

int main() {
    Graphics graphics;
    Window window;
    Menu menu;

    window.initialConfig();
    window.hideCursor(true);

    graphics.drawBombCanvas();
    graphics.drawMainMenu();

    int op;
    while(true) {
        op = menu.showMainMenu();

        switch (op) {
            case 0:
                graphics.drawGameBox();
                menu.gameMenu();
                getch();
                break;
            case 1:
                // how to play
                break;
            case 2:
                // about
                break;
            case 3:
                return 0;
        }
    }
}
