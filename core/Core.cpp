#include "Core.h"
#include "Graph.h"
#include <stdexcept>

int gen_chains_all(char* words[], int len, char* result[]) {
    Graph graph(words, len, result);
    if (graph.hasCircle()) {
        throw std::logic_error("Circle detected");
    }
    return graph.genChainsAll();
}

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop) {
    Graph graph(words, len, result, except);
    if (graph.hasCircle()) {
        if (!enable_loop) {
            throw std::logic_error("Circle detected, please add -r to support circle");
        }
        return graph.genChainWordWithCircle(head, tail);
    } else {
        return graph.genChainWordWithoutCircle(head, tail);
    }
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop) {
    Graph graph(words, len, result, except);
    if (graph.hasCircle()) {
        if (!enable_loop) {
            throw std::logic_error("Circle detected, please add -r to support circle");
        }
        return graph.genChainCharWithCircle(head, tail);
    } else {
        return graph.genChainCharWithoutCircle(head, tail);
    }
}