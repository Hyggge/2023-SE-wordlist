#include "FileParser.h"
#include <string>
#include <fstream>

FileParser::FileParser(const std::string &filename) {
    std::ifstream ifs;
    ifs.open(filename);
    if (ifs.fail()) {
        // todo: throw exception
    }

    char head = '\0', last = '\0';
    bool isParsingWord = false;
    this->wordsNum = 0;


    while (! ifs.eof()) {
        char ch = (char)ifs.get();
        if (isalpha(ch) && !isParsingWord) {
            head = ch;
            isParsingWord = true;
        } else if (!isalpha(ch) && isParsingWord) {
            this->words[this->wordsNum] = (char *) malloc(3 * sizeof(char));
            this->words[this->wordsNum][0] = head;
            this->words[this->wordsNum][1] = last;
            this->words[this->wordsNum][2] = '\0';
            this->wordsNum++;
            isParsingWord = false;
        }
        last = ch;
    }

}

char** FileParser::getWords() {
    return words;
}

int FileParser::getWordsNum() const {
    return wordsNum;
}