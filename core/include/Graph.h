#ifndef WORDLIST_GRAPH_H
#define WORDLIST_GRAPH_H

#include <vector>

struct Edge {
    int wordId, to;
};

class Graph {
private:
    std::vector<Edge> g[26];

    void addEdge(int u, int v, int wordId);

public:
    Graph(char* words[], int len, char except = '\0');

    bool hasCircle();

    int genChainsAll(char* result[]);

    int genChainWordWithCircle(char* result[], char head, char tail);

    int genChainWordWithoutCircle(char* result[], char head, char tail);

    int genChainCharWithCircle(int len, char* result[], char head, char tail);

    int genChainCharWithoutCircle(char* result[], char head, char tail);
};

#endif //WORDLIST_GRAPH_H