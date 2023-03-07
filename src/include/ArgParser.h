#ifndef WORDLIST_ARGPARSER_H
#define WORDLIST_ARGPARSER_H

#include <string>

struct UserOptions {
    bool n, w, c, r;
    char h, t, j;

    UserOptions() {
        n = false;
        w = false;
        c = false;
        r = false;
        h = '\0';
        t = '\0';
        j = '\0';
    }
};

class ArgParser {
private:
    UserOptions userOptions;
    std::string filename;

public:
    ArgParser(int argc, char* argv[]);

    UserOptions getOptions();

    std::string getFilename();
};

#endif //WORDLIST_ARGPARSER_H