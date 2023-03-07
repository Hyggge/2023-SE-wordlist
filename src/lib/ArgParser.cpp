#include "ArgParser.h"
#include <cstring>
#include <cctype>

bool checkEndWithDotTxt(char* str) {
    int l = (int) strlen(str);
    if (l < 4) {
        return false;
    }
    return str[l - 1] == 't' && str[l - 2] == 'x' && str[l - 3] == 't' && str[l - 4] == '.';
}

ArgParser::ArgParser(int argc, char **argv) {
    this->userOptions = UserOptions();
    this->filename = "";
    for (int i = 1; i < argc; ++i) {
        char* str = argv[i];
        if (checkEndWithDotTxt(str)) {
            this->filename = str;
        } else if (str[0] == '-' && strlen(str) == 2) {
            switch (str[1]) {
                case 'n':
                    this->userOptions.n = true;
                    break;
                case 'w':
                    this->userOptions.w = true;
                    break;
                case 'c':
                    this->userOptions.c = true;
                    break;
                case 'r':
                    this->userOptions.r = true;
                    break;
                case 'h':
                    if (i + 1 < argc && strlen(argv[i + 1]) == 1 && isalpha(argv[i + 1][0])) {
                        this->userOptions.h = (char) tolower(argv[i + 1][0]);
                        ++i;
                    } else {
                        // todo: throw exception: -h usage error: "argv[i + 1]"
                    }
                    break;
                case 't':
                    if (i + 1 < argc && strlen(argv[i + 1]) == 1 && isalpha(argv[i + 1][0])) {
                        this->userOptions.t = (char) tolower(argv[i + 1][0]);
                        ++i;
                    } else {
                        // todo: throw exception: -t usage error: "argv[i + 1]"
                    }
                    break;
                case 'j':
                    if (i + 1 < argc && strlen(argv[i + 1]) == 1 && isalpha(argv[i + 1][0])) {
                        this->userOptions.j = (char) tolower(argv[i + 1][0]);
                        ++i;
                    } else {
                        // todo: throw exception: -j usage error: "argv[i + 1]"
                    }
                    break;
                default:
                    // todo: throw exception: no matching option error: "-x" undefined
            }
        } else {
            // todo: throw exception: argument parsing error: "argv"
        }
    }
}

UserOptions ArgParser::getOptions() {
    return userOptions;
}

std::string ArgParser::getFilename() {
    return filename;
}