#ifndef WORDLIST_CONTROLLER_H
#define WORDLIST_CONTROLLER_H

#include "ArgParser.h"

class Controller {
private:
    UserOptions userOptions;
    char** words;
    int len;

public:
    Controller(UserOptions userOptions, char* words[], int len);

    void run();
};

#endif //WORDLIST_CONTROLLER_H