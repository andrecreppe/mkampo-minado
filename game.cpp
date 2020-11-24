#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "game.h"
#include "graphics.h"
#include "menu.h"

// 0 = hidden, -1 = flagged, -2 = bomb!
// 1 - 10 = bomb count (+1)
int field[10][10];

void Game::playMineField() {
    Menu menu;
    Graphics graphics;

    while(true) {
        Game::initializeField();

        graphics.drawGameBox(field);

        int x = menu.rowSelection(field);
        int y = menu.columnSelection(x, field);

        int op = menu.cellOperation();

        switch (op) {
            case 0:
                stepOn(x, y);
                break;
            case 1:
                // mark
                break;
        }
    }
}

void Game::initializeField() {
//    memset(field, 0, sizeof(field)); // fill with 0
//
//    srand(time(NULL));
//
//    // Sort bombs
//    int bombCount = 12;
//    for(int i=0; i<bombCount; i++) {
//        int x = rand() % 10; // 0 - 9
//        int y = rand() % 10; // 0 - 9
//
//        if(field[y][x] == 0) {
//            field[y][x] = -2;
//        } else {
//            i--;
//        }
//    }

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            field[j][i] = i+1;
        }
    }
}

void Game::stepOn(int, int) {

}

void Game::reveal3x3(int x, int y) {
    int count = 0;

    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(i == 0 && j == 0) continue;

            int val = field[y+j][x+i];
            if(val == -2) count++;
        }
    }

//    field[x][y] = (count == 0) ? -1 : count;
}
