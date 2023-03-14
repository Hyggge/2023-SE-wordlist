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

    char** words;
    int word2Len[10005];

    char** result;
    int resultLen = 0;

    std::vector<int> wordIdStack;
    std::vector<int> selfCircleWordIdList[26];

    bool hasCircleFlag = false;

    void addEdge(int u, int v, int wordId);

    void toposort();

    void dfsChainsAll(int cur, bool allowSelfCircle);

    void dfsChainWordWithCircle(int cur, char tail, std::vector<int>& curChain, std::vector<int>& maxChain, bool* visited);

    void dfsChainCharWithCircle(int cur, char tail,std::vector<int>& curChain, std::vector<int>& maxChain, bool* visited, int curCharNum, int& maxCharNum);

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