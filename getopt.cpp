#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "getopt.h"
#include "utils.h"

void Getopt(int argc, const char** argv, Option* options) {
    for (; argc > 0; argc--, argv++) {
        const char* opts = *argv;
        if (strlen(opts)  < 2 || opts[0] != '-') {
            continue;
        }

        if (opts[1] == '-') {
            ParseLong(opts, options);
        } else {
            if (opts[2] != '=' && opts[2] != '\0') {
                continue;
            }
            ParseShort(opts, options);
        }
    }
}

void ParseLong(const char* opts, Option* option) {
    assert(opts   != NULL);
    assert(option != NULL);

    opts += 2; // skip --

    // const char* beginOpt = opts;
    const char* endOpt = strchr(opts, '=');

    while (1) {
        if (Stop(option)) {
            return;
        }
                                            // (size_t)(endOpt - beginOpt)
        if (strncmp(opts, option->longName, strlen(option->longName)) == 0) {
            option->seen = true;
            break;
        };

        option++;
    }

    if (endOpt == NULL) {
        option->nArgs = 0;
        return;
    }

    opts = endOpt;

    ParseArgs(option, opts);
}

void ParseShort(const char* opts, Option* option) {
    assert(opts   != NULL);
    assert(option != NULL);

    opts++; // skip -

    while (1) {
        if (Stop(option)) {
            return;
        }

        if (option->shortName == *opts) {
            option->seen = true;
            break;
        }

        option++;
    }

    opts++; // skip name

    if (*opts != '=') {
        option->nArgs = 0;
        option->data = NULL;
        return;
    }

    ParseArgs(option, opts);
}

bool Stop(Option* option) {
    assert(option != NULL);

    return (option->longName  == NULL &&
            option->shortName == '\0' &&
            option->func      == NULL);
}

void Strcpy(char* dest,const  char* begin,const char* end) { // копирует строку [begin, end) после чего терменирует \0
    assert(dest  != NULL);
    assert(begin != NULL);
    assert(end   != NULL);

    while (begin != end) {
        *dest = *begin;
        dest++;
        begin++;
    }
    *dest = '\0';
}

// bool IsEql(const char* begin, const char* end, const char* str) { // [begin, end)
//     assert(begin != NULL);
//     assert(end   != NULL);
//     assert(str   != NULL);

//     while (begin != end) {
//         if (*begin != *str) {
//             return false;
//         }
//         str++;
//         begin++;
//     }
//     if (*str != '\0') {
//         return false;
//     } else {
//         return true;
//     }
// }

void FreeOpt(Option* option) {
    for (int i = 0; !Stop(option+i); i++) {
        for (size_t j = 0; j < option[i].nArgs; j++) {
            free(option[i].data[j]);
        }
        free(option[i].data);
        option[i].data = nullptr;
    }
}

void PrintOpt(Option* option) {
    for (int i = 0; !Stop(option+i); i++) {
        printf("long name: %s\n",           option[i].longName);
        printf("short name: %c\n",          option[i].shortName);
        printf("had been seen: %d\n",       option[i].seen);
        printf("has number of args: %lu\n", option[i].nArgs);
        printf("args:\n");
        for (size_t j = 0; j < option[i].nArgs; j++) {
            printf("%s ",option[i].data[j]);
        }
        printf("\n");
    }
}

void ParseArgs(Option* option, const char* pos) { //  передавать указатель на =
    pos++; // skip =
    (option->nArgs)++;

    for (const char* cntComma = pos; *cntComma != '\0'; cntComma++) {
        if (*cntComma == ',') {
            (option->nArgs)++;
        }
    }

    option->data = (char**)calloc(option->nArgs, sizeof(option->data[0]));

    char** dataRef = option->data;
    const char* term = strchr(pos, '\0');

    while (*pos != '\0') {
        // const char* tmpptr = pos;
        // while (*tmpptr != ',' && *tmpptr != '\0') {
        //     tmpptr++;
        // }

        const char* comma = strchr(pos, ',');

        const char* jump = (comma != NULL) ? comma : term;

        size_t size = (size_t)(jump - pos + 1); // длинна аргумента + \0
        *dataRef = (char*)calloc(size, sizeof((*dataRef)[0]));

        Strcpy(*dataRef, pos, jump);
        dataRef++;

        if (*jump == '\0') {
            break;
        } else {
            pos = jump + 1;
        }
    }
}
