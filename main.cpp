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

    graphics.loading();

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
                graphics.tutorial();
                break;
            case 2:
                graphics.about();
                break;
            case 3:
                if(menu.exitMenu() == 0) {
                    graphics.exiting();
                    return 0;
                }
                break;
        }
    }
}
