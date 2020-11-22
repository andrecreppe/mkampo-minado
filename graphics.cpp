#include <stdio.h>

#include "graphics.h"
#include "window.h"

void Graphics::drawCanvas() {
    Window window;

    window.textColor(0);
    //Fundo + Formato
    for(int i=50; i<=110; i++) {
        window.gotoxy(i,5);printf("%c", 219);
    }
    for(int i=46; i<115; i++) {
        window.gotoxy(i,6);printf("%c", 219);
    }
    for(int i=34; i<127; i++) {
        window.gotoxy(i,7);printf("%c", 219);
    }
    for(int i=30; i<131; i++) {
        window.gotoxy(i,8);printf("%c", 219);
    }
    for(int i=9; i<=31; i++) {
        window.gotoxy(28,i);printf("%c", 219);
        window.gotoxy(29,i);printf("%c", 219);
        window.gotoxy(30+101,i);printf("%c", 219);
        window.gotoxy(31+101,i);printf("%c", 219);
    }
    for(int i=9; i<=31; i++) {

        window.gotoxy(28,i);printf("%c", 219);
        window.gotoxy(29,i);printf("%c", 219);
        window.gotoxy(30+101,i);printf("%c", 219);
        window.gotoxy(31+101,i);printf("%c", 219);
    }
    for(int i=30; i<131; i++) {
        window.gotoxy(i,32);printf("%c", 219);
    }
    for(int i=40; i<121; i++) {
        window.gotoxy(i,33);printf("%c", 219);
    }
    for(int i=50; i<83; i++) {
        window.gotoxy(i,34);printf("%c", 219);
        window.gotoxy(i+28,34);printf("%c", 219);
    }
    for(int i=30 ; i<131 ; i++) {
        for(int j=8 ; j<32 ; j++) {
            window.gotoxy(i,j); printf("%c", 219);
        }
    }
}
