#ifndef MKAMPO_MINADO_MENU_H
#define MKAMPO_MINADO_MENU_H


class Menu {
public:
    // Main
    static int showMainMenu();
    // Game
    static int rowSelection();
    static int columnSelection(int);
    static int cellOperation();
};


#endif //MKAMPO_MINADO_MENU_H
