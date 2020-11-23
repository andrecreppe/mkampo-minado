#include <iostream>
#include <conio.h>

#include "menu.h"
#include "window.h"
#include "graphics.h"
#include "game.h"

using namespace std;

int main() {
    Graphics graphics;
    Window window;
    Menu menu;
    Game game;

    window.initialConfig();
    window.hideCursor(true);

    graphics.drawBombCanvas();
    graphics.drawMainMenu();

    int op;
    while(true) {
        op = menu.showMainMenu();

        switch (op) {
            case 0:
                game.playMineField();
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
