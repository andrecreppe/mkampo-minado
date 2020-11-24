#ifndef MKAMPO_MINADO_GRAPHICS_H
#define MKAMPO_MINADO_GRAPHICS_H


class Graphics {
public:
    // Design
    static void drawBombCanvas();
    static void drawGameBox(int[10][10]);
    // Interface
    static void drawMainMenu();
    static void clearMainMenu();
    // Gameplay
    static void writeSelection(int, bool);
    static int getFieldChar(int);
    static void showMines(int[10][10]);
    static void gameOver();
};


#endif //MKAMPO_MINADO_GRAPHICS_H
