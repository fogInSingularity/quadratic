#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "getopt.h"
#include "utils.h"

void Getopt(int argc, char** argv, Option* options) {
    for (;argc > 0; argc--, argv++) {
        char* opts = *argv;
        if (strlen(opts)  < 2 || opts[0] != '-') {
            continue;
        }

        if (opts[1] == '-') {
            ParseLong(opts, options);
        } else {
            ParseShort(opts, options);
        }
    }
}

void ParseLong(const char* opts, Option* option) {
    assert(opts   != NULL);
    assert(option != NULL);

    opts += 2; // skip --
    const char* beginOpt = opts;
    const char* endOpt = opts;
    while (*endOpt != '=' && *endOpt != '\0') {
        endOpt++;
    }

    for (; Stop(option); option++) {
        if (IsEql(beginOpt, endOpt, option->longName)) {
            option->seen = true;
            break;
        }
    }
    if (Stop(option)) {
        return;
    }

    opts = endOpt; // skip name

    if (*opts != '=') {
        option->nArgs = 0;
        option->data = NULL;
        return;
    }
    opts++; // skip =
    (option->nArgs)++;

    for (const char* tmpptr = opts; *tmpptr != '\0'; tmpptr++) {
        if (*tmpptr == ',') {
            (option->nArgs)++;
        }
    }

    (option->data) = (char**)calloc(option->nArgs, sizeof(char**));

    char** dataRef = option->data;
    while (*opts != '\0') {
        const char* tmpptr = opts;
        while (*tmpptr != ',' && *tmpptr != '\0') {
            tmpptr++;
        }

        size_t size = (size_t)(tmpptr - opts + 1); // длинна аргумента + \0
        *dataRef = (char*)calloc(size, sizeof(char*));

        Strcpy(*dataRef, opts, tmpptr);
        dataRef++;

        if (*tmpptr == '\0') {
            opts = tmpptr;
        } else {
            opts = tmpptr + 1;
        }
    }
}

void ParseShort(const char* opts, Option* option) {
    assert(opts   != NULL);
    assert(option != NULL);

    opts++; // skip -
    for (; Stop(option); option++) {
        if (option->shortName == *opts) {
            option->seen = true;
            break;
        }
    }
    if (Stop(option)) {
        return;
    }
    opts++; // skip name

    if (*opts != '=') {
        option->nArgs = 0;
        option->data = NULL;
        return;
    }
    opts++; // skip =
    (option->nArgs)++;

    for (const char* tmpptr = opts; *tmpptr != '\0'; tmpptr++) {
        if (*tmpptr == ',') {
            (option->nArgs)++;
        }
    }

    (option->data) = (char**)calloc(option->nArgs, sizeof(char**));

    char** dataRef = option->data;
    while (*opts != '\0') {
        const char* tmpptr = opts;
        while (*tmpptr != ',' && *tmpptr != '\0') {
            tmpptr++;
        }

        size_t size = (size_t)(tmpptr - opts + 1); // длинна аргумента + \0
        *dataRef = (char*)calloc(size, sizeof(char*));

        Strcpy(*dataRef, opts, tmpptr);
        dataRef++;

        if (*tmpptr == '\0') {
            opts = tmpptr;
        } else {
            opts = tmpptr + 1;
        }
    }
}

bool Stop(Option* option) {
    assert(option != NULL);

    return (option->longName  == NULL &&
            option->shortName == '\0' &&
            option->funcPtr   == NULL) ? true : false;
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
