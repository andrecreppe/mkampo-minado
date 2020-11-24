#include "menu.h"
#include "window.h"
#include "graphics.h"
#include "game.h"

int main() {
    Graphics graphics;
    Window window;
    Menu menu;
    Game game;

    window.initialConfig();
    window.hideCursor(true);

    int op;
    while(true) {
        graphics.drawBombCanvas();
        graphics.drawMainMenu();

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
