#ifndef WORDLIST_GRAPH_H
#define WORDLIST_GRAPH_H

#include <vector>

struct Edge {
    int wordId, to;
};

class Graph {
private:
    std::vector<Edge> g[26];
    int toposortInDegree[26] = {0};
    int toposortSequence[26] = {0};
    int previousNode[26] = {0};

    char** words;

    char** result;
    int resultLen = 0;

    std::vector<int> wordIdStack;

    std::vector<int> selfCircleWordIdList[26];

    void addEdge(int u, int v, int wordId);

    void dfsChainsAll(int cur, bool allowSelfCircle);

public:
    Graph(char* words[], int len, char* result[], char except = '\0');

    bool hasCircle();

    int genChainsAll();

    int genChainWordWithCircle(char head, char tail);

    int genChainWordWithoutCircle(char head, char tail);

    int genChainCharWithCircle(char head, char tail);

    int genChainCharWithoutCircle(char head, char tail);
};

#endif //WORDLIST_GRAPH_H