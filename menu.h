#ifndef MKAMPO_MINADO_MENU_H
#define MKAMPO_MINADO_MENU_H


class Menu {
public:
    // Main
    static int showMainMenu();
    static int exitMenu();
    // Game
    static int rowSelection(int[10][10]);
    static int columnSelection(int, int[10][10]);
    static int cellOperation();
};


#endif //MKAMPO_MINADO_MENU_H
