#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "game.h"
#include "graphics.h"
#include "menu.h"

#include "window.h"
#include <stdio.h>

// 0 = hidden, -1 = flagged, -2 = bomb!
// 1 - 10 = bomb count (+1)
int field[10][10];

void Game::playMineField() {
    Menu menu;
    Graphics graphics;

    Game::initializeField();

    while(true) {
        graphics.drawGameBox(field);

        int y = menu.rowSelection(field);
        int x = menu.columnSelection(y, field);

        int op = menu.cellOperation();

        switch (op) {
            case 0:
                if(field[y][x] == -2) {
                    Window::gotoxy(0, 15);
                    printf("GAME OVER");
                    return;
                }

                count3x3(y, x);
                break;
            case 1:
                // mark
                break;
        }
    }
}

void Game::initializeField() {
    memset(field, 0, sizeof(field)); // fill with 0

    srand(time(NULL));

    // Sort bombs
    int bombCount = 12;
    for(int i=0; i<bombCount; i++) {
        int x = rand() % 10; // 0 - 9
        int y = rand() % 10; // 0 - 9

        if(field[y][x] == 0) {
            field[y][x] = -2;
        } else {
            i--;
        }
    }
}

void Game::count3x3(int y, int x) {
    int count = 0;

    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int posx = x+i;
            int posy = y+j;

            if(i == 0 && j == 0) continue;
            if(posx < 0 || posy < 0) continue;

            int val = field[posy][posx];
            if(val == -2) count++;
        }
    }

    field[y][x] = count+1;
}
