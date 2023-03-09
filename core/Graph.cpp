#include "Graph.h"
#include "cstdlib"
#include <cstring>
#include <queue>
#include <vector>

void Graph::addEdge(int u, int v, int wordId) {
    g[u].push_back({wordId, v});
    ++toposortInDegree[v];
}

Graph::Graph(char* words[], int len, char* result[], char except) {
    for (int i = 0; i < len; ++i) {
        if (words[i][0] == except) {
            continue;
        }
        int from = words[i][0] - 'a';
        int to = words[i][strlen(words[i]) - 1] - 'a';
        if (from == to) {
            selfCircleWordIdList[from].push_back(i);
        } else {
            addEdge(words[i][0] - 'a', words[i][strlen(words[i]) - 1] - 'a', i);
        }
    }
    this->words = words;
    this->result = result;
}

bool Graph::hasCircle() {
    for (int i = 0; i < 26; ++i) {
        if (selfCircleWordIdList[i].size() > 1) {
            return true;
        }
    }
    // toposort
    std::queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (toposortInDegree[i] == 0) {
            q.push(i);
        }
    }
    int cur = 0;
    while (!q.empty()) {
        int k = q.front();q.pop();
        toposortSequence[cur++] = k;
        for (Edge &e : g[k]) {
            if (--toposortInDegree[e.to] == 0) {
                q.push(e.to);
            }
        }
    }
    return cur < 26;
}

void Graph::dfsChainsAll(int cur, bool allowSelfCircle) {
    if (wordIdStack.size() >= 2) {
        std::vector<char> buffer;
        for (int id : wordIdStack) {
            char* word = words[id];
            for (int i = 0; word[i] != '\0'; ++i) {
                buffer.push_back(word[i]);
            }
            buffer.push_back(' ');
        }
        buffer.pop_back();
        result[resultLen] = (char *) malloc((buffer.size() + 1) * sizeof(char));
        for (int i = 0; i < buffer.size(); ++i) {
            result[resultLen][i] = buffer[i];
        }
        result[resultLen][buffer.size()] = '\0';
        ++resultLen;
    }
    // self circle
    if (selfCircleWordIdList[cur].size() == 1 && allowSelfCircle) {
        wordIdStack.push_back(selfCircleWordIdList[cur][0]);
        dfsChainsAll(cur, false);
        wordIdStack.pop_back();
    }
    // other edges
    for (Edge &e : g[cur]) {
        wordIdStack.push_back(e.wordId);
        dfsChainsAll(e.to, true);
        wordIdStack.pop_back();
    }
}

int Graph::genChainsAll() {
    for (int i = 0; i < 26; ++i) {
        dfsChainsAll(i, true);
    }
    return resultLen;
}

int Graph::genChainWordWithCircle(char head, char tail) {
    return 0;
}

int Graph::genChainWordWithoutCircle(char head, char tail) {
    int dp[26] = {0};
    int pre[26] = {0};
    int maxLen = 0;
    int maxPos = -1;

    for (int i = 0; i < 26; ++i) {
        pre[i] = -1;
    }
    if (head != '\0') {
        for (int i = 0; i < 26; ++i) {
            dp[i] = -2147483647;
        }
        dp[head - 'a'] = 0;
    }

    for (int i = 0; i < 26; ++i) {
        int cur = toposortSequence[i];
        if (selfCircleWordIdList[cur].size() > 0) dp[cur]++;
        if (dp[cur] > maxLen) {
            maxLen = dp[cur];
            maxPos = cur;
        }
        if (tail != '\0' && cur == tail - 'a') {
            maxLen = dp[cur];
            maxPos = cur;
            break;
        }
    }


    return ;
}

int Graph::genChainCharWithCircle(char head, char tail) {
    return 0;
}

int Graph::genChainCharWithoutCircle(char head, char tail) {
    return 0;
}
