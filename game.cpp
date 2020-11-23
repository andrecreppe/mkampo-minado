#include <conio.h>

#include "game.h"
#include "graphics.h"
#include "menu.h"

void Game::playMineField() {
    Menu menu;
    Graphics graphics;

    while(true) {
        graphics.drawGameBox();
        int row = menu.rowSelection();
        int col = menu.columnSelection(row);

        int op = menu.cellOperation();

        switch (op) {
            case 0:
                // step
                break;
            case 1:
                // mark
                break;
        }
    }
}