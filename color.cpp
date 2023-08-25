#include <stdio.h>
#include <stdarg.h>

#include "color.h"

// \x1b[1;34m мод с цветом 34
// \x1b[0m выключение модов
// printf("\x1b[1;34mHello\n\x1b[0m");
void printc(const char str[], COLOR color, ...){
    va_list args; // хранит инфу для функций
    va_start(args, str); // даёт доступ к аргументам

    printf("\x1b[1;%dm", color);

    // for(int i = 0; str[i] != 0;){
    //     if(str[i] == '%'){
    //         // форматный символ
    //     }
    // }

    printf("%s", str);

    printf("\x1b[0m");


    va_end(args); // закрывает доступ к аргументам
}
