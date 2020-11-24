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
};


#endif //MKAMPO_MINADO_GRAPHICS_H
