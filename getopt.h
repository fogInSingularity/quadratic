#ifndef GETOPT_H
#define GETOPT_H


struct Option {
    const char* longName;
    char shortName;
    void (*funcPtr) (void*);
    bool seen; // иниц false
    size_t nArgs; // иниц 0
    char** data; // иниц NULL
};


void Getopt(int argc, char** argv, Option* options);


void ParseLong(const char* opts, Option* options);


void ParseShort(const char* opts, Option* options);


bool Stop(Option* option);


void Strcpy(char* dest,const  char* begin,const char* end);


bool IsEql(const char* begin, const char* end, const char* str);


#endif // GETOPT_H
