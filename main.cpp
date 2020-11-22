#include <iostream>

#include "menu.h"
#include "window.h"
#include "graphics.h"

using namespace std;

int main() {
    Graphics graphics;
    Window window;
    Menu menu;

    window.initialConfig();
    window.hideCursor(true);

    graphics.drawCanvas();

    int op;
    do {
        op = menu.showMenu();
        window.gotoxy(0,0); cout << op;
    } while(op != 3);

    return 0;
}
