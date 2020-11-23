#ifndef MKAMPO_MINADO_WINDOW_H
#define MKAMPO_MINADO_WINDOW_H


class Window {
public:
    // Configuration
    static void initialConfig();
    static void gotoxy(int, int);

    // Visuals
    static void hideCursor(bool);
    static void textColor(int);
};


#endif //MKAMPO_MINADO_WINDOW_H
