#include "FileParser.h"
#include <string>

FileParser::FileParser(std::string filename) {

}

char** FileParser::getWords() {
    return words;
}

int FileParser::getWordsNum() const {
    return wordsNum;
}