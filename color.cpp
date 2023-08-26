#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#include "color.h"

void TurnOnColor(Color color) {
    printf("\x1b[0;%dm", color);
}

void TurnOnStyle(Style style) {
    printf("\x1b[%dm", style);
}

void TurnOffColor() {
    printf("\x1b[;%dm", Color::DEFAULT_CLR);
}

void TurnOffStyle(Style style) {
    switch (style) {
        case BOLD:
            printf("\x1b[22m");
            break;
        case DIM:
            printf("\x1b[22m");
            break;
        case ITALIC:
            printf("\x1b[23m");
            break;
        case UDERLINE:
            printf("\x1b[24m");
            break;
        case BLINKING:
            printf("\x1b[25m");
            break;
        case INVERSE:
            printf("\x1b[27m");
            break;
        case HIDDEN:
            printf("\x1b[28m");
            break;
        case STRIKETHROUGH:
            printf("\x1b[29m");
            break;
        default:
            assert(0 && "something went wrong with style");
            break;
    }
}

void TurnOffAll() {
    printf("\x1b[0m");
}

void ShowAll() {
    printf("\x1b[0;30mHello \x1b[1;30mHello\n");
    printf("\x1b[0;31mHello \x1b[1;31mHello\n");
    printf("\x1b[0;32mHello \x1b[1;32mHello\n");
    printf("\x1b[0;33mHello \x1b[1;33mHello\n");
    printf("\x1b[0;34mHello \x1b[1;34mHello\n");
    printf("\x1b[0;35mHello \x1b[1;35mHello\n");
    printf("\x1b[0;36mHello \x1b[1;36mHello\n");
    printf("\x1b[0;37mHello \x1b[1;37mHello\n");
    printf("\x1b[0;39mHello \x1b[1;39mHello\n");
    printf("\x1b[0m");
    printf("\x1b[0;40mHello \n");
    printf("\x1b[0;41mHello \n");
    printf("\x1b[0;42mHello \n");
    printf("\x1b[0;43mHello \n");
    printf("\x1b[0;44mHello \n");
    printf("\x1b[0;45mHello \n");
    printf("\x1b[0;46mHello \n");
    printf("\x1b[0;47mHello \n");
    printf("\x1b[0;49mHello \n");
    printf("\x1b[0m");
    printf("\x1b[1mHello\x1b[0m\n");
    printf("\x1b[2mHello\x1b[0m\n");
    printf("\x1b[3mHello\x1b[0m\n");
    printf("\x1b[4mHello\x1b[0m\n");
    printf("\x1b[5mHello\x1b[0m\n");
    printf("\x1b[7mHello\x1b[0m\n");
    printf("\x1b[8mHello\x1b[0m\n");
    printf("\x1b[9mHello\x1b[0m\n");
}
