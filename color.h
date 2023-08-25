#ifndef COLOR_H
#define COLRO_H

enum COLOR {
    BLACK       = 30,
    RED         = 31,
    CREEN       = 32,
    YELLOW      = 33,
    BLUE        = 34,
    MAGENTA     = 35,
    CYAN        = 36,
    WHITE       = 37,
    DEFAULT_CLR = 38,
};

void printc(const char str[], COLOR color, ...);

#endif // COLOR_H
