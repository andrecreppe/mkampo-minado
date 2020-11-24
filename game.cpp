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
// 1 - 10 = bomb count (1 => 0, ..., 10 => 9)
int mineField[10][10];
int graphicField[10][10];

void Game::playMineField() {
    Menu menu;
    Graphics graphics;

    initializeField();

    while(true) {
        graphics.drawGameBox(graphicField);

        int y = menu.rowSelection(graphicField);
        int x = menu.columnSelection(y, graphicField);

        int op = menu.cellOperation();

        switch (op) {
            case 0:
                if(mineField[y][x] == -2) {
                    graphics.showMines(mineField);
                    graphics.gameOver();
                    getch();
                    return;
                }

                count3x3(y, x);
                break;
            case 1:
                graphicField[y][x] = -1;
                break;
        }
    }
}

void Game::initializeField() {
    memset(mineField, 0, sizeof(mineField)); // fill with 0
    memset(graphicField, 0, sizeof(graphicField)); // fill with 0

    srand(time(NULL));

    // Sort bombs
    int bombCount = 12;
    for(int i=0; i<bombCount; i++) {
        int x = rand() % 10; // 0 - 9
        int y = rand() % 10; // 0 - 9

        if(mineField[y][x] == 0) {
            mineField[y][x] = -2;
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

            int val = mineField[posy][posx];
            if(val == -2) count++;
        }
    }

    graphicField[y][x] = count+1;
}
