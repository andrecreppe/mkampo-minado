#include <conio.h>
#include <iostream>

#include "menu.h"
#include "window.h"

using namespace std;

int main() {
    Window window;
    Menu menu;

    window.initialConfig();
    window.hideCursor(true);

    int op;
    do {
        op = menu.showMenu();
        window.gotoxy(0,0); cout << op;
    } while(op != 3);

    return 0;
}
