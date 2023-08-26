#ifndef COLOR_H
#define COLOR_H


/// @brief enum that holds text colors
enum Color {
    BLACK       = 30, BLACK_BACK   = 40,
    RED         = 31, RED_BACK     = 41,
    GREEN       = 32, GREEN_BACK   = 42,
    YELLOW      = 33, YELLOW_BACK  = 43,
    BLUE        = 34, BLUE_BACK    = 44,
    MAGENTA     = 35, MAGENTA_BACK = 45,
    CYAN        = 36, CYAN_BACK    = 46,
    WHITE       = 37, WHITE_BACK   = 47,
    DEFAULT_CLR = 39, DEFAULT_BACK = 49,
};


/// @brief enum that holds text style
enum Style {
    BOLD          = 1,
    DIM           = 2,
    ITALIC        = 3,
    UDERLINE      = 4,
    BLINKING      = 5,
    INVERSE       = 7,
    HIDDEN        = 8,
    STRIKETHROUGH = 9,
};


/**
 * @brief turns on given color
 *
 * @param color chosen color to set
*/
void TurnOnColor(Color color);


/**
 * @brief turns on given style
 *
 * @param style chosen style to set
*/
void TurnOnStyle(Style style);


/**
 * @brief turns off color (sets to deafult)
*/
void TurnOffColor();


/**
 * @brief turns off given style
*/
void TurnOffStyle(Style style);


/**
 * @brief turns off all color and style
*/
void TurnOffAll();


/**
 * @brief function that shows all colors and styles
*/
void ShowAll();

#endif // COLOR_H
