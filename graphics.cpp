#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "graphics.h"
#include "window.h"

using namespace std;

// Design

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

    window.textColor(8);
    window.gotoxy(x1,y1);  printf("  )");
    window.gotoxy(x1,y1+1);printf(" (");
    window.gotoxy(x2,y2);  printf("  )");
    window.gotoxy(x2,y2+1);printf(" (");

    window.textColor(12);
    window.gotoxy(x1,y1+2);printf(".-`-.");
    window.gotoxy(x1,y1+3);printf(":   :");
    window.gotoxy(x1,y1+4);printf(":   :");
    window.gotoxy(x1,y1+5);printf(":___:");
    window.gotoxy(x2,y2+2);printf(".-`-.");
    window.gotoxy(x2,y2+3);printf(":   :");
    window.gotoxy(x2,y2+4);printf(":   :");
    window.gotoxy(x2,y2+5);printf(":___:");

    window.textColor(15);
    window.gotoxy(x1+1,y1+4);printf("TNT");
    window.gotoxy(x2+1,y2+4);printf("TNT");
}

void Graphics::drawUSP() {
    // Logo anchor
    int x = 8, y = 1;

    // Logo drawing

    Window window;

    window.gotoxy(x,y);   printf("%@@@@@@@@@@@@@@@@@@@@  *@@@@@@@@@@@@@@@@.   *@@@@@@@@@@@@@@@@,");
    window.gotoxy(x,y+1); printf("%@         @(        @@                 /@@@,                ,@%");
    window.gotoxy(x,y+2); printf("%@         @(       (@.         %        /@                   *@,");
    window.gotoxy(x,y+3); printf("%@         @(       (@           @@                 @@        *@,");
    window.gotoxy(x,y+4); printf("%@         @(       (@           @@                 @@        *@,");
    window.gotoxy(x,y+5); printf("%@         @(        %@&           %@@              @@        ,@,");
    window.gotoxy(x,y+6); printf("%@         @(           @@,           @@,           @@        ,@,");
    window.gotoxy(x,y+7); printf("%@         @(             #@%           #@&         @@########%@,");
    window.gotoxy(x,y+8); printf("%@         @(                @@          *@         @@");
    window.gotoxy(x,y+9); printf("%@                   @@                  /@         @@");
    window.gotoxy(x,y+10);printf(" @@,                @@&@/               &@*         @@");
    window.gotoxy(x,y+11);printf("   .#@@@@@@@@@@@@@&,     #@@@@@@@@@@@@@*   @@@@@@@@@@@");
}

// Pages

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

    window.textColor(15);
    window.gotoxy(x+14, y+21);printf("<Aperte qualquer tecla para voltar>");

    getch();
}

void Graphics::about() {
    // Box anchor
    int x = 8, y = 15;
    int width = 62, height = 12;
    int padR = 2;

    // Box maker

    system("cls");

    drawUSP();

    Window window;
    window.textColor(0);

    window.gotoxy(x,y);
    printf("%c", 201);
    for(int i=0; i<28; i++) printf("%c", 205);
    printf(" SOBRE ");
    for(int i=35; i<width; i++) printf("%c", 205);
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

    window.textColor(9);
    window.gotoxy(x+padR, y+2);printf("DISCIPLINA:");

    window.textColor(0);
    window.gotoxy(x+padR, y+3);printf("  SEM0580 - Topicos em Computacao (2020)");
    window.gotoxy(x+padR, y+4);printf("  Prof. Dr. Mario Luiz Tronco");

    window.textColor(9);
    window.gotoxy(x+padR, y+6);printf("AUTORES:");

    window.textColor(0);
    window.gotoxy(x+padR, y+7);printf("  Andre Zanardi Creppe - 11802972");
    window.gotoxy(x+padR, y+8);printf("  Gabriel de Oliveira Maia - 11819790");
    window.gotoxy(x+padR, y+9);printf("  Renan Henrique de Sousa - 11802947");
    window.gotoxy(x+padR, y+10);printf("  Vitor Malosso Micheletti - 10738291");

    window.textColor(15);
    window.gotoxy(x+14, y+12);printf("<Aperte qualquer tecla para voltar>");

    getch();
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

void Graphics::drawExitMenu() {
    clearMainMenu();

    int x = 6, y = 3;

    Window window;
    window.gotoxy(x+4, y);printf(" Sair ");

    window.gotoxy(x, y+1);printf("Confirmar sair");
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

    window.textColor(15);
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
    window.gotoxy(x, y+1);printf(" Pontos: (%d)", points);

    window.textColor(15);
    window.gotoxy(x, y+3);printf("Tecle algo pra");
    window.gotoxy(x, y+4);printf("voltar ao menu");
}

// Animations
void Graphics::loading() {
    // Animation anchor
    int x1 = 1, y1 = 3;
    int x2 = 15, y2 = 16;
    int delay = 100;

    Window window;

    // Title drawing

    window.gotoxy(x1,y1);   printf("___  ____   __ ___ ___  ________ _____  ___  ________ _    _  ___ ______ _____");
    window.gotoxy(x1,y1+1); printf("|  \\/  | | / // _ \\|  \\/  | ___ |  _  | |  \\/  |_   _| \\ | |/ _ \\|  _  |  _  |");
    window.gotoxy(x1,y1+2); printf("| .  . | |/ // /_\\ | .  . | |_/ | | | | | .  . | | | |  \\| / /_\\ | | | | | | |");
    window.gotoxy(x1,y1+3); printf("| |\\/| |    \\|  _  | |\\/| |  __/| | | | | |\\/| | | | | . ` |  _  | | | | | | |");
    window.gotoxy(x1,y1+4); printf("| |  | | |\\  | | | | |  | | |   \\ \\_/ / | |  | |_| |_| |\\  | | | | |/ /\\ \\_/ /");
    window.gotoxy(x1,y1+5); printf("\\_|  |_\\_| \\_\\_| |_\\_|  |_\\_|    \\___/  \\_|  |_/\\___/\\_| \\_\\_| |_|___/  \\___/");

    // Animation drawing

    window.gotoxy(x2,y2);   printf(" ______________________________     . \\  | /  .");
    window.gotoxy(x2,y2+1); printf("/                            / \\     \\ \\ / /");
    window.gotoxy(x2,y2+2); printf("|                            | ==========  - - -");
    window.gotoxy(x2,y2+3); printf("\\____________________________\\_/     / / \\ \\");
    window.gotoxy(x2,y2+4); printf("                                    .  / | \\  .");

    window.textColor(15);
    window.gotoxy(x2+8, y2+2); printf("LOADING [0%]");

    this_thread::sleep_for(chrono::milliseconds(400));

    // Animation - TNT body

    for(int i=0; i<29; i++) {
        window.textColor(12);

        if(i == 0) {
            window.gotoxy(x2, y2+1); printf("/");
            window.gotoxy(x2, y2+2); printf("|");
            window.gotoxy(x2, y2+3); printf("\\");
        } else {
            window.gotoxy(x2+i, y2); printf("_");
            window.gotoxy(x2+i, y2+3); printf("_");
        }

        window.textColor(15);
        window.gotoxy(x2+16, y2+2); printf("[%d%]", i*2);

        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    window.textColor(12);
    window.gotoxy(x2+29, y2+0); printf("_");
    window.gotoxy(x2+29, y2+1); printf("/");
    window.gotoxy(x2+29, y2+2); printf("|");
    window.gotoxy(x2+29, y2+3); printf("\\");

    window.textColor(15);
    window.gotoxy(x2+16, y2+2); printf("[%d%]", 60);

    this_thread::sleep_for(chrono::milliseconds(delay));

    window.textColor(12);
    window.gotoxy(x2+30, y2); printf("_");
    window.gotoxy(x2+30, y2+1); printf(" \\");
    window.gotoxy(x2+30, y2+3); printf("_/");

    window.textColor(15);
    window.gotoxy(x2+16, y2+2); printf("[%d%]", 64);

    this_thread::sleep_for(chrono::milliseconds(delay));

    // Animation - TNT fuse

    for(int i=31; i<41; i++) {
        window.textColor(8);
        window.gotoxy(x2+i, y2+2); printf("=");

        window.textColor(15);
        window.gotoxy(x2+16, y2+2); printf("[%d%]", i+36);

        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    // Animation - Sparks

    window.textColor(14);
    window.gotoxy(x2+37, y2+1); printf("\\ \\ / /");
    window.gotoxy(x2+37, y2+3); printf("/ / \\ \\");

    window.textColor(15);
    window.gotoxy(x2+16, y2+2); printf("[%d%]", 81);

    this_thread::sleep_for(chrono::milliseconds(delay));

    window.textColor(14);
    window.gotoxy(x2+36, y2); printf(". \\  | /  .");
    window.gotoxy(x2+36, y2+4); printf(".  / | \\  .");

    window.textColor(15);
    window.gotoxy(x2+16, y2+2); printf("[%d%]", 86);

    this_thread::sleep_for(chrono::milliseconds(delay));

    for(int i=43; i<48; i+=2) {
        window.textColor(14);
        window.gotoxy(x2+i, y2+2); printf("-");

        window.textColor(15);
        window.gotoxy(x2+16, y2+2); printf("[%d%]", i+46);

        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    window.gotoxy(x2+8, y2+2); printf("LOADING COMPLETE!");

    this_thread::sleep_for(chrono::milliseconds(1000));
}

void Graphics::exiting() {
    // Animation anchor
    int x1 = 36, y1 = 2;
    int x2 = 15, y2 = 3;

    int timeFuse = 150;
    int time = 10;

    // Animate fuse

    Window window;

    window.gotoxy(x1, y1);   cout << "       ";
    window.gotoxy(x1, y1+1); cout << " . . .  ";
    window.gotoxy(x1, y1+2); cout << "  \\|/  ";
    window.gotoxy(x1, y1+3); cout << "'--+--'";
    window.gotoxy(x1, y1+4); cout << "  /|\\ ";
    window.gotoxy(x1, y1+5); cout << " ' | '";
    window.gotoxy(x1, y1+6); cout << "   |";
    this_thread::sleep_for(chrono::milliseconds(timeFuse));

    window.gotoxy(x1, y1+1); cout << "       ";
    window.gotoxy(x1, y1+2); cout << " . . .  ";
    window.gotoxy(x1, y1+3); cout << "  \\|/  ";
    window.gotoxy(x1, y1+4); cout << "'--+--'";
    window.gotoxy(x1, y1+5); cout << "  /|\\ ";
    window.gotoxy(x1, y1+6);  cout << " ' | '";
    this_thread::sleep_for(chrono::milliseconds(timeFuse));

    window.gotoxy(x1, y1+2); cout << "       ";
    window.gotoxy(x1, y1+3); cout << " . . .  ";
    window.gotoxy(x1, y1+4); cout << "  \\|/  ";
    window.gotoxy(x1, y1+5); cout << "'--+--'";
    window.gotoxy(x1, y1+6); cout << "  /|\\ ";
    this_thread::sleep_for(chrono::milliseconds(timeFuse));

    // Animate explosion

    system("cls");

    window.gotoxy(x2,y2+22); printf("        (/ / //  /|//||||\\\\  \\ \\  \\ _)");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+21); printf("          (     //|/l|||)|\\\\ \\     )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+20); printf("        (        |(||(||)||||        )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+19); printf("          (      ||\\(|(|)|/||     )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+18); printf("         (     ( ((((_(|)_)))))     )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+17); printf("           (   /(| / ( )) ) ) )) )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+16); printf("          (    ( ( ( | | ) ) )\\   )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+15); printf("            (   /(/ (  )  ) )\\   )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+14); printf("   ((__)        \\\\||lll|l||///          \\_))");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+13); printf("   (_((__(_(__(( ( ( |  ) ) ) )_))__))_)___)");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+12); printf("  ((  (   )(    (     _    )   _) _(_ (  (_ )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+11); printf(" ( (  ( (  (  )     (_  )  ) )  _)   ) _( ( )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+10); printf("  (  (   (  (   (_ ( ) ( _    )  ) (  )  )   )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+9); printf(" ( (  ( \\ ) (    (_  ( ) ( )  )   ) )  )) ( )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+8); printf("  ( (  (   ) (  )   (  ))     ) _)(   )  )  )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+7); printf("  (  (   (  (   ) (  _  ( _) ).  ) . ) ) ( )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+6); printf("   ( (  )    (      (  )    )   ) . ) (   )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+5); printf("    ( (  ( (_)   ((    (   )  .((_ ) .  )_");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+4); printf("     ((/  ( _(   )   (   _) ) (  () )  )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+3); printf("       ((     (   )(    )  )   (   )  )");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+2); printf("         /( (  (  )   _    ))  )   )\\");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2+1); printf("          ____/ (  (    )   )  \\___");
    this_thread::sleep_for(chrono::milliseconds(time));
    window.gotoxy(x2,y2);   printf("               ________________");

    this_thread::sleep_for(chrono::milliseconds(1000));
}
