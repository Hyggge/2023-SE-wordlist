#ifndef WORDLIST_CONTROLLER_H
#define WORDLIST_CONTROLLER_H

#include <cstdio>
#include "ArgParser.h"
#include "Constant.h"

class Controller {
private:
    UserOptions userOptions;
    char** words;
    int len;
    char* result[10000] = {nullptr};

public:
    Controller(UserOptions userOptions, char* words[], int len);

    ~Controller();

    void run();
};

#endif //WORDLIST_CONTROLLER_H