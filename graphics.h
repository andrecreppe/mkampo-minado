#ifndef MKAMPO_MINADO_GRAPHICS_H
#define MKAMPO_MINADO_GRAPHICS_H


class Graphics {
public:
    // Design
    static void drawBombCanvas();
    static void drawGameBox(int[10][10]);
    static void drawTNTs();
    static void drawUSP();
    // Pages
    static void tutorial();
    static void about();
    // Interface
    static void drawMainMenu();
    static void clearMainMenu();
    static void drawExitMenu();
    // Gameplay
    static void writeSelection(int, bool);
    static int getFieldChar(int);
    static void showMines(int[10][10]);
    static void gameOver(int);
    // Animations
    static void loading();
    static void exiting();
};


#endif //MKAMPO_MINADO_GRAPHICS_H
