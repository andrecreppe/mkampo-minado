#include <iostream>

#include "graphics.h"
#include "window.h"

using namespace std;

// Design

/*
             %@@@@@@@@@@@@@@@@@@@@  *@@@@@@@@@@@@@@@@.   *@@@@@@@@@@@@@@@@,
             %@         @(        @@                 /@@@,                ,@%
             %@         @(       (@.         %        /@                   *@,
             %@         @(       (@           @@                 @@        *@,
             %@         @(        %@&           %@@              @@        ,@,
             %@         @(           @@,           @@,           @@        ,@,
             %@         @(             #@%           #@&         @@########%@,
             %@         @(                @@          *@         @@
             %@                   @@                  /@         @@
              @@,                @@&@/               &@*         @@
                .#@@@@@@@@@@@@@&,     #@@@@@@@@@@@@@*   @@@@@@@@@@@
 */

void Graphics::drawBombCanvas() {
    // Art anchor
    int x = 23, y = 2;

    // ASCII Drawing
    Window window;

    system("cls");

    window.textColor(0);

    window.gotoxy(x, y);   cout << "              . . .";
    window.gotoxy(x, y+1); cout << "               \\|/";
    window.gotoxy(x, y+2); cout << "             '--+--'";
    window.gotoxy(x, y+3); cout << "               /|\\";
    window.gotoxy(x, y+4); cout << "              ' | '";
    window.gotoxy(x, y+5); cout << "                |";
    window.gotoxy(x, y+6); cout << "                |";
    window.gotoxy(x, y+7); cout << "           ,--'###`--.";
    window.gotoxy(x, y+8); cout << "           |#########|";
    window.gotoxy(x, y+9); cout << "        _.-'#########`-._";
    window.gotoxy(x, y+10);cout << "     ,-'#################`-.";
    window.gotoxy(x, y+11);cout << "   ,'#######################`,";
    window.gotoxy(x, y+12);cout << "  /###########################\\";
    window.gotoxy(x, y+13);cout << " |#############################|";
    window.gotoxy(x, y+14);cout << "|###############################|";
    window.gotoxy(x, y+15);cout << "|###############################|";
    window.gotoxy(x, y+16);cout << "|###############################|";
    window.gotoxy(x, y+17);cout << "|###############################|";
    window.gotoxy(x, y+18);cout << "|###############################|";
    window.gotoxy(x, y+19);cout << "|###############################|";
    window.gotoxy(x, y+20);cout << " |#############################|";
    window.gotoxy(x, y+21);cout << "  \\###########################/";
    window.gotoxy(x, y+22);cout << "   `.#######################,'";
    window.gotoxy(x, y+23);cout << "     `._#################_,'";
    window.gotoxy(x, y+24);cout << "        `--..#######..--'";
}

void Graphics::drawGameBox(int field[10][10]) {
    // Box anchor
    int x = 29, y = 13;
    int width = 19, height = 10;

    // Box maker

    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<width; i++) printf("%c", 205);
    printf("%c", 187);

    int val, mchar;

    for(int i=1; i<=height; i++) {
        window.gotoxy(x, y+i);printf("%c", 186);
        window.gotoxy(x+width+1, y+i);printf("%c", 186);

        for(int j=0; j<18; j+=2) {
            val = field[i-1][j/2];
            mchar = getFieldChar(val);

            window.gotoxy(x+1+j, y+i);printf("%c ", mchar);
        }
        val = field[i-1][9];
        mchar = getFieldChar(val);

        window.gotoxy(x+19, y+i);printf("%c", mchar);
    }

    window.gotoxy(x,y+height+1);
    printf("%c", 200);
    for(int i=0; i<width; i++) printf("%c", 205);
    printf("%c", 188);
}

void Graphics::drawTNTs() {
    // TNT anchor
    int x1 = 2, y1 = 10;
    int x2 = 73, y2 = 10;

    // TNT drawing

    Window window;

    window.gotoxy(x1,y1);printf("  )");
    window.gotoxy(x1,y1+1);printf(" (");
    window.gotoxy(x1,y1+2);printf(".-`-.");
    window.gotoxy(x1,y1+3);printf(":   :");
    window.gotoxy(x1,y1+4);printf(":TNT:");
    window.gotoxy(x1,y1+5);printf(":___:");

    window.gotoxy(x2,y2);printf("  )");
    window.gotoxy(x2,y2+1);printf(" (");
    window.gotoxy(x2,y2+2);printf(".-`-.");
    window.gotoxy(x2,y2+3);printf(":   :");
    window.gotoxy(x2,y2+4);printf(":TNT:");
    window.gotoxy(x2,y2+5);printf(":___:");
}

void Graphics::tutorial() {
    // Box anchor
    int x = 8, y = 3;
    int width = 62, height = 21;
    int padR = 2;

    // Box maker

    system("cls");

    drawTNTs();

    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<26; i++) printf("%c", 205);
    printf(" TUTORIAL ");
    for(int i=36; i<width; i++) printf("%c", 205);
    printf("%c", 187);

    for(int i=1; i<=height; i++) {
        window.gotoxy(x, y+i);printf("%c", 186);
        window.gotoxy(x+width+1, y+i);printf("%c", 186);
    }

    window.gotoxy(x,y+height+1);
    printf("%c", 200);
    for(int i=0; i<width; i++) printf("%c", 205);
    printf("%c", 188);

    // Text writer

    setlocale(LC_ALL, "Portuguese");

    window.textColor(9);
    window.gotoxy(x+padR, y+2);printf("OBJETIVO:");

    window.textColor(0);
    window.gotoxy(x+padR, y+3);printf("  Descobrir todas as casas do campo sem que alguma exploda.");

    window.textColor(9);
    window.gotoxy(x+padR, y+5);printf("O JOGO:");

    window.textColor(0);
    window.gotoxy(x+padR, y+6);printf("  Para selecionar um quadrado basta navegar usando as setas");
    window.gotoxy(x+padR, y+7);printf("do teclado por meio de linhas e depois colunas e comfirmar.");

    window.gotoxy(x+padR, y+9);printf("  Caso uma das 12 minas (#) seja descoberta, o jogo acaba.");
    window.gotoxy(x+padR, y+10);printf("Se um quadrado vazio for descoberto, um numero aparece para");
    window.gotoxy(x+padR, y+11);printf("informar quantas minas estao escondidas nos 8 quadrados");
    window.gotoxy(x+padR, y+12);printf("adjacentes. Esse dado pode ser usado para deduzir em quais");
    window.gotoxy(x+padR, y+13);printf("outros quadrados existe, ou nao, bombas.");

    window.gotoxy(x+padR, y+15);printf("  Para evitar 'acidentes', pode-se marcar uma casa com uma");
    window.gotoxy(x+padR, y+16);printf("bandeira onde achar que existe uma mina.");

    window.textColor(9);
    window.gotoxy(x+padR, y+18);printf("PONTOS:");

    window.textColor(0);
    window.gotoxy(x+padR, y+19);printf("   Cada casa descoberta garante 1 ponto ao jogador.");

    window.gotoxy(x+14, y+21);printf("<Aperte qualquer tecla para voltar>");

    setlocale(LC_ALL, "C");

    getchar();
}

// Interface

void Graphics::drawMainMenu() {
    // Menu anchor
    int x = 5, y = 3;
    int width = 14, height = 4;

    // Bomb art
    clearMainMenu();

    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<4; i++) printf("%c", 205);
    printf(" Menu ");
    for(int i=10; i<width; i++) printf("%c", 205);
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

void Graphics::clearMainMenu() {
    int x = 6, y = 3;
    int width = 14, height = 5;

    Window window;

    window.textColor(0);

    window.gotoxy(x, y);
    for(int i=0; i<width; i++) printf("%c", 205);

    for(int i=1; i<height; i++) {
        window.gotoxy(x, y+i);
        for(int j=0; j<width; j++) {
            printf(" ");
        }
    }
}

// Gameplay

void Graphics::writeSelection(int val, bool isCol) {
    int x = 6, y = 4;

    string text[] = {"linha ", "coluna "};

    clearMainMenu();

    Window window;
    window.textColor(0);

    window.gotoxy(x, y);cout << "  Selecionar";
    window.gotoxy(x, y+1);cout << text[isCol];
    printf("(%d) do", val);
    if (val < 10) printf(" ");
    window.gotoxy(x, y+2);cout << "mkampo minado?";
    window.gotoxy(x, y+3);cout << "   <Enter>";
}

int Graphics::getFieldChar(int val) {
    // 0 = hidden, -1 = flagged, -2 = bomb!
    // 1 - 10 = bomb count (1 => 0, ..., 10 => 9)

    int hidden = 254;
    int bomb = 35;
    int flag = 33;
    int empty = 46;

    if(val == 0) {
        return hidden;
    } else if(val == -1) {
        return flag;
    } else if(val == -2) {
        return bomb;
    }

    if(val == 1) {
        return empty;
    }

    return (47 + val);
}

void Graphics::showMines(int field[10][10]) {
    int x = 30, y = 14;
    int mineColor = 12;

    Window window;

    window.textColor(mineColor);

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(field[j][i] == -2) {
                window.gotoxy(x+(2*i), y+j);
                printf("%c", getFieldChar(-2));
            }
        }
    }
}

void Graphics::gameOver(int points) {
    clearMainMenu();

    int x = 6, y = 3;

    Window window;
    window.textColor(12);
    window.gotoxy(x+1, y);printf(" GAME OVER! ");

    window.textColor(0);
    window.gotoxy(x, y+1);printf("Pontos: (%d)", points);
    window.gotoxy(x, y+3);printf("Tecle algo pra");
    window.gotoxy(x, y+4);printf("voltar ao menu");
}
