#include "FileParser.h"
#include <string>
#include <fstream>
#include <vector>
#include "Exceptions.h"

FileParser::FileParser(const std::string &filename) {
    if (filename.empty()) {
        throw NoInputFileException();
    }
    std::ifstream ifs;
    ifs.open(filename);
    if (ifs.fail()) {
        throw FileOpenException(filename.c_str());
    }
    std::vector<char> buffer;
    this->wordsNum = 0;

    while (! ifs.eof()) {
        char ch = (char)ifs.get();
        if (isalpha(ch)) {
            buffer.push_back(ch);
        }
        else if (! isalpha(ch) && ! buffer.empty()) {
            int size = (int)buffer.size();
            this->words[this->wordsNum] = (char *) malloc((size + 1) * sizeof(char));
            for (int i = 0; i < size; ++i) {
                this->words[this->wordsNum][i] = buffer[i];
            }
            this->words[this->wordsNum][size] = '\0';
            this->wordsNum++;
            buffer.clear();
        }
    }
}

FileParser::~FileParser() {
    for (char* &word : this->words) {
        free(word);
    }
}

char** FileParser::getWords() {
    return words;
}

int FileParser::getWordsNum() const {
    return wordsNum;
}