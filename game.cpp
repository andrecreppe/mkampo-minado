#include <conio.h>

#include "game.h"
#include "graphics.h"
#include "menu.h"

void Game::playMineField() {
    Menu menu;
    Graphics graphics;

    graphics.drawGameBox();
    int row = menu.rowSelection();
    int column = menu.columnSelection(row);
    getch();
}