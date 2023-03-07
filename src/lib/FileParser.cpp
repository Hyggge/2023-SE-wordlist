#include "FileParser.h"
#include <string>
#include <fstream>
#include <vector>
#include <set>

FileParser::FileParser(const std::string &filename) {
    std::ifstream ifs;
    ifs.open(filename);
    if (ifs.fail()) {
        // todo: throw exception
    }
    std::vector<char> buffer;
    std::set<std::string> wordSet;
    this->wordsNum = 0;


    while (! ifs.eof()) {
        char ch = (char)ifs.get();
        if (isalpha(ch)) {
            buffer.push_back(ch);
        }
        else if (! isalpha(ch) && ! buffer.empty()) {
            int size = (int)buffer.size();
            std::string word = std::string(buffer.data(), buffer.size());
            if (wordSet.count(word) == 0) {
                this->words[this->wordsNum] = (char *) malloc((size + 1) * sizeof(char));
                for (int i = 0; i < size; ++i) {
                    this->words[this->wordsNum][i] = buffer[i];
                }
                this->words[this->wordsNum][size] = '\0';
                this->wordsNum++;
                wordSet.insert(word);
            }
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