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
    const char* beginOpt = opts;
    // const char* endOpt = opts;
    // while (*endOpt != '=' && *endOpt != '\0') {
    //     endOpt++;
    // }

    const char* endOpt = strchr(opts, '=');

    // for (; !Stop(option); option++) {
    //     if (IsEql(beginOpt, endOpt, option->longName)) {
    //         option->seen = true;
    //         break;
    //     }
    // }
    // if (Stop(option)) {
    //     return;
    // }

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

    // opts = endOpt; // skip name
    // printf("opts: %s\n", opts);
    // printf("point\n");
    // if (*opts != '=') {
    //     option->nArgs = 0;
    //     return;
    // }

    ParseArgs(option, opts);
}

void ParseShort(const char* opts, Option* option) {
    assert(opts   != NULL);
    assert(option != NULL);

    opts++; // skip -

    // for (; !Stop(option); option++) {
    //     if (option->shortName == *opts) {
    //         option->seen = true;
    //         break;
    //     }
    // }
    // if (Stop(option)) {
    //     return;
    // }

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

bool IsEql(const char* begin, const char* end, const char* str) { // [begin, end)
    assert(begin != NULL);
    assert(end   != NULL);
    assert(str   != NULL);

    while (begin != end) {
        if (*begin != *str) {
            return false;
        }
        str++;
        begin++;
    }
    if (*str != '\0') {
        return false;
    } else {
        return true;
    }
}

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

void ParseArgs(Option* option, const char* pos) {
    pos++; // skip =
    (option->nArgs)++;

    for (const char* tmpptr = pos; *tmpptr != '\0'; tmpptr++) {
        if (*tmpptr == ',') {
            (option->nArgs)++;
        }
    }

    option->data = (char**)calloc(option->nArgs, sizeof(option->data[0]));

    char** dataRef = option->data;
    while (*pos != '\0') {
        const char* tmpptr = pos;
        while (*tmpptr != ',' && *tmpptr != '\0') {
            tmpptr++;
        }

        size_t size = (size_t)(tmpptr - pos + 1); // длинна аргумента + \0
        *dataRef = (char*)calloc(size, sizeof((*dataRef)[0]));

        Strcpy(*dataRef, pos, tmpptr);
        dataRef++;

        if (*tmpptr == '\0') {
            break;
        } else {
            pos = tmpptr + 1;
        }
    }
}
