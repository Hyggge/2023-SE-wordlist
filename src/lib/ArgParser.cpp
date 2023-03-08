#include "ArgParser.h"
#include <cstring>
#include <cctype>
#include "Exceptions.h"

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
                        throw OptionUsageException(str);
                    }
                    break;
                case 't':
                    if (i + 1 < argc && strlen(argv[i + 1]) == 1 && isalpha(argv[i + 1][0])) {
                        this->userOptions.t = (char) tolower(argv[i + 1][0]);
                        ++i;
                    } else {
                        throw OptionUsageException(str);
                    }
                    break;
                case 'j':
                    if (i + 1 < argc && strlen(argv[i + 1]) == 1 && isalpha(argv[i + 1][0])) {
                        this->userOptions.j = (char) tolower(argv[i + 1][0]);
                        ++i;
                    } else {
                        throw OptionUsageException(str);
                    }
                    break;
                default:
                    throw BadOptionException(str);
            }
        } else if (str[0] == '-' && strlen(str) != 2) {
            throw BadOptionException(str);
        } else {
            throw UnknownCommandException(str);
        }
    }
}

UserOptions ArgParser::getOptions() {
    return userOptions;
}

std::string ArgParser::getFilename() {
    return filename;
}