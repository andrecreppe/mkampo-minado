#include <clocale>
#include <windows.h>

#include "window.h"

// Configuration

void Window::initialConfig() {
    system("TITLE MKampo Minado");
    system("mode con: cols=80 lines=30");
    system("COLOR 70");
    system("cls");

    setlocale(LC_ALL, NULL);
}

void Window::gotoxy(int x, int y) {
    COORD c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Visuals

void Window::hideCursor(bool show){
    CONSOLE_CURSOR_INFO cursor;

    cursor = {20, !show};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void Window::textColor(int color) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        (csbi.wAttributes & 0xf0) | color
    );
}
