#ifndef GETOPT_H
#define GETOPT_H


struct Option {
    const char* longName;
    char shortName;
    void (*func) (Option* option);
    bool seen; // иниц false
    size_t nArgs; // иниц 0
    char** data; // иниц NULL
};


void Getopt(int argc, const char** argv, Option* options);


void ParseLong(const char* opts, Option* options);


void ParseShort(const char* opts, Option* options);


bool Stop(Option* option);


void Strcpy(char* dest, const char* begin, const char* end);


// bool IsEql(const char* begin, const char* end, const char* str);


void FreeOpt(Option* option);


void PrintOpt(Option* option);


void ParseArgs(Option* option, const char* pos);


#endif // GETOPT_H
