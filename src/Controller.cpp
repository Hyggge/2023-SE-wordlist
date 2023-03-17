#include "Controller.h"
#include "Core.h"
#include "Exceptions.h"
#include <cstdio>

Controller::Controller(UserOptions userOptions, char* words[], int len) {
   this->userOptions = userOptions;
   this->words = words;
   this->len = len;
}

Controller::~Controller() {
//    for (char* &word : this->result) {
//        free(word);
//    }
}

void Controller::run() {
    // check options
    if (userOptions.n + userOptions.w + userOptions.c == 0) {
        throw MissingFunctionalOptionException();
    } else if (userOptions.n + userOptions.w + userOptions.c > 1 ||
        userOptions.n && (userOptions.h + userOptions.t + userOptions.j > 0)) {
        throw OptionIncompatibilityException();
    }

    // call Core API
    int resultLen = 0;
    static char field[10000][20000];
    for (int i = 0; i < 10000; ++i) {
        this->result[i] = field[i];
    }

    if (userOptions.n) {
        resultLen = gen_chains_all(words, len, result);
    } else if (userOptions.w) {
        resultLen = gen_chain_word(words, len, result, userOptions.h, userOptions.t, userOptions.j, userOptions.r);
    } else {
        resultLen = gen_chain_char(words, len, result, userOptions.h, userOptions.t, userOptions.j, userOptions.r);
    }

    // cannot find result
    if (resultLen <= 0) throw NoResultException();

    // open file to write
    FILE *fp = fopen("solution.txt", "w");
    if (fp == nullptr) {
        throw FileOpenException("solution.txt");
    }

    // print result
    if (userOptions.n) {
        printf("%d\n", resultLen);
        fprintf(fp, "%d\n", resultLen);
    }
    for (int i = 0; i < resultLen; i++) {
        printf("%s\n", result[i]);
        fprintf(fp, "%s\n", result[i]);
    }
}