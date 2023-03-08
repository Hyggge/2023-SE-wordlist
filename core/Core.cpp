#include "Core.h"
#include "Graph.h"
#include <stdexcept>

int gen_chains_all(char* words[], int len, char* result[]) {
    Graph graph(words, len);
    if (graph.hasCircle()) {
        throw std::logic_error("Circle detected");
    }
    return graph.genChainsAll(result);
}

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop) {
    Graph graph(words, len, except);
    if (graph.hasCircle()) {
        if (!enable_loop) {
            throw std::logic_error("Circle detected, please add -r to support circle");
        }
        return graph.genChainWordWithCircle(result, head, tail);
    } else {
        return graph.genChainWordWithoutCircle(result, head, tail);
    }
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop) {
    Graph graph(words, len, except);
    if (graph.hasCircle()) {
        if (!enable_loop) {
            throw std::logic_error("Circle detected, please add -r to support circle");
        }
        return graph.genChainCharWithCircle(len, result, head, tail);
    } else {
        return graph.genChainCharWithoutCircle(result, head, tail);
    }
}