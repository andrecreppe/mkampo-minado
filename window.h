#ifndef MKAMPO_MINADO_WINDOW_H
#define MKAMPO_MINADO_WINDOW_H


class Window {
public:
    // Configuration
    void initialConfig();
    void gotoxy(int, int);

    // Visuals
    void hideCursor(bool);
    void textColor(int);
};


#endif //MKAMPO_MINADO_WINDOW_H
