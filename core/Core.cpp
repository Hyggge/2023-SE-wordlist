#include "Core.h"
#include "Graph.h"
#include <stdexcept>
#include <cctype>

int gen_chains_all(char* words[], int len, char* result[]) {
    // check the validity of parameters
    if (words == nullptr) throw std::invalid_argument("Value of words can't be null");
    if (len < 0) throw std::invalid_argument("Value of len can't be less than 0");
    if (result == nullptr) throw std::invalid_argument("Value of result can't be null");

    // build graph and calculate
    Graph graph(words, len, result);
    if (graph.hasCircle()) {
        throw std::logic_error("Circle detected");
    }
    return graph.genChainsAll();
}

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop) {
    // check the validity of parameters
    if (words == nullptr) throw std::invalid_argument("Value of words can't be null");
    if (len < 0) throw std::invalid_argument("Value of len can't be less than 0");
    if (result == nullptr) throw std::invalid_argument("Value of result can't be null");
    if (head != '\0' && !isalpha(head)) throw std::invalid_argument("Value of head must be a letter");
    if (tail != '\0' && !isalpha(tail)) throw std::invalid_argument("Value of tail must be a letter");
    if (except != '\0' && !isalpha(except)) throw std::invalid_argument("Value of except must be a letter");

    // build graph and calculate
    Graph graph(words, len, result, except);
    Graph* graphWithAllWords = (except == '\0') ? &graph : new Graph(words, len, result);

    if (graphWithAllWords->hasCircle() && !enable_loop) {
        throw std::logic_error("Circle detected");
    } else if (graph.hasCircle()) {
        return graph.genChainWordWithCircle(head, tail);
    } else {
        return graph.genChainWordWithoutCircle(head, tail);
    }
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop) {
    // check the validity of parameters
    if (words == nullptr) throw std::invalid_argument("Value of words can't be null");
    if (len < 0) throw std::invalid_argument("Value of len can't be less than 0");
    if (result == nullptr) throw std::invalid_argument("Value of result can't be null");
    if (head != '\0' && ! isalpha(head)) throw std::invalid_argument("Value of head must be a letter");
    if (tail != '\0' && ! isalpha(tail)) throw std::invalid_argument("Value of tail must be a letter");
    if (except != '\0' && ! isalpha(except)) throw std::invalid_argument("Value of except must be a letter");

    // build graph and calculate
    Graph graph(words, len, result, except);
    Graph* graphWithAllWords = (except == '\0') ? &graph : new Graph(words, len, result);

    if (graphWithAllWords->hasCircle() && !enable_loop) {
        throw std::logic_error("Circle detected");
    } else if (graph.hasCircle()) {
        return graph.genChainCharWithCircle(head, tail);
    } else {
        return graph.genChainCharWithoutCircle(head, tail);
    }
}