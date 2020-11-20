#include <conio.h>

#include "menu.h"
#include "window.h"

using namespace std;

int main() {
    Window window;
    Menu menu;

    window.initialConfig();
    window.hideCursor(true);

    menu.showMenu();

//    window.gotoxy(40, 20);
//    window.textColor(14);
//    menu.showMenu();
//
//    window.gotoxy(50, 30);
//    window.textColor(13);
//    menu.showMenu();

    getch();
    return 0;
}
