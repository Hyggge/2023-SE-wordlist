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
        word2Len[i] = (int)strlen(words[i]);
        int from = words[i][0] - 'a';
        int to = words[i][word2Len[i] - 1] - 'a';
        if (from == to) {
            selfCircleWordIdList[from].push_back(i);
        } else {
            addEdge(words[i][0] - 'a', words[i][word2Len[i] - 1] - 'a', i);
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

void Graph::dfsChainWordWithCircle(int cur, char tail, std::vector<int>& curChain, std::vector<int>& maxChain, bool* visited) {
    if ((tail == '\0' || tail == cur) && curChain.size() > maxChain.size()) {
        maxChain = std::vector<int>(curChain);
    }
    for (Edge& edge : g[cur]) {
        if (! visited[edge.wordId]) {
            visited[edge.wordId] = true;
            curChain.push_back(edge.wordId);
            dfsChainWordWithCircle(edge.to, tail, curChain, maxChain, visited);
            curChain.pop_back();
            visited[edge.wordId] = false;
        }
    }
}

int Graph::genChainWordWithCircle(char head, char tail) {
    std::vector<int> curChain;
    std::vector<int> maxChain;
    bool visited[10005] = {false}; // todo

    if (head != '\0') {
        dfsChainWordWithCircle(head - 'a', tail, curChain, maxChain, visited);
    } else {
        for (int i = 0; i < 26; ++i) {
            dfsChainWordWithCircle(i, tail, curChain, maxChain, visited);
        }
    }
    for (int i = 0; i < maxChain.size(); ++i) {
        char *word = words[maxChain[i]];
        result[i] = (char *) malloc((word2Len[maxChain[i]] + 1) * sizeof(char));
        strcpy(result[i], word);
    }
    resultLen = (int) maxChain.size();
    return resultLen;
}

int Graph::genChainWordWithoutCircle(char head, char tail) {
    int dp[26] = {0};
    std::pair<int, int> pre[26]; // first: pre node, second: word id of the edge
    int maxWordNum = 0;
    int maxPos = -1;
    // init `pre`
    for (auto & item : pre) {
        item.first = -1;
        item.second = -1;
    }
    // if `head` is not '\0', we should only set dp[head - 'a'] = 0, and other dp[i] = -2147483647
    // by this means, we can ensure that the first letter of the longest word chain is always `head`
    if (head != '\0') {
        for (int i = 0; i < 26; ++i) {
            dp[i] = -2147483647;
        }
        dp[head - 'a'] = 0;
    }
    // dp according to topology order
    for (int cur : toposortSequence) {
        if (! selfCircleWordIdList[cur].empty()) {
            dp[cur]++;
        }
        if (dp[cur] > maxWordNum) {
            maxWordNum = dp[cur];
            maxPos = cur;
        }
        if (tail != '\0' && cur == tail - 'a') {
            maxWordNum = dp[cur];
            maxPos = cur;
            break;
        }
        for (Edge &e : g[cur]) {
            if (dp[e.to] < dp[cur] + 1) {
                dp[e.to] = dp[cur] + 1;
                pre[e.to] = {cur, e.wordId};
            }
        }

    }
    // find the specific longest word chain with `maxPos` and `pre`
    int cur = maxPos;
    for (int i = maxWordNum - 1; i >= 0; --i) {
        if (! selfCircleWordIdList[cur].empty()) {
            int wordId = selfCircleWordIdList[cur][0];
            result[i] = (char *) malloc((word2Len[wordId] + 1) * sizeof(char));
            strcpy(result[i], words[wordId]);
            --i;
        }
        int wordId = pre[cur].second;
        result[i] = (char *) malloc((word2Len[wordId] + 1) * sizeof(char));
        strcpy(result[i], words[wordId]);
    }

    resultLen = maxWordNum;
    return resultLen;
}

void Graph::dfsChainCharWithCircle(int cur, char tail,std::vector<int>& curChain, std::vector<int>& maxChain, bool* visited, int curCharNum, int& maxCharNum) {
    if ((tail == '\0' || tail == cur) && curCharNum > maxCharNum) {
        maxChain = std::vector<int>(curChain);
    }
    for (Edge& edge : g[cur]) {
        if (! visited[edge.wordId]) {
            visited[edge.wordId] = true;
            curChain.push_back(edge.wordId);
            dfsChainCharWithCircle(edge.to, tail, curChain, maxChain, visited, curCharNum +  word2Len[edge.wordId], maxCharNum);
            curChain.pop_back();
            visited[edge.wordId] = false;
        }
    }
}

int Graph::genChainCharWithCircle(char head, char tail) {
    std::vector<int> curChain;
    std::vector<int> maxChain;
    int curCharNum = 0;
    int maxCharNum = 0;
    bool visited[10005] = {false}; // todo

    if (head != '\0') {
        dfsChainCharWithCircle(head - 'a', tail, curChain, maxChain, visited, curCharNum, maxCharNum);
    } else {
        for (int i = 0; i < 26; ++i) {
            dfsChainCharWithCircle(i, tail, curChain, maxChain, visited, curCharNum, maxCharNum);
        }
    }
    for (int i = 0; i < maxChain.size(); ++i) {
        int wordId = maxChain[i];
        result[i] = (char *) malloc((word2Len[wordId] + 1) * sizeof(char));
        strcpy(result[i], words[wordId]);
    }
    resultLen = (int) maxChain.size();
    return resultLen;
}

int Graph::genChainCharWithoutCircle(char head, char tail) {
    int dp[26] = {0};
    int wordNum[26] = {0};
    std::pair<int, int> pre[26]; // first: pre node, second: word id of the edge
    int maxCharNum = 0;
    int maxPos = -1;
    // init `pre`
    for (auto & item : pre) {
        item.first = -1;
        item.second = -1;
    }
    // if `head` is not '\0', we should only set dp[head - 'a'] = 0, and other dp[i] = -2147483647
    // by this means, we can ensure that the first letter of the longest word chain is always `head`
    if (head != '\0') {
        for (int i = 0; i < 26; ++i) {
            dp[i] = -2147483647;
        }
        dp[head - 'a'] = 0;
    }
    // dp according to topology order
    for (int cur : toposortSequence) {
        if (! selfCircleWordIdList[cur].empty()) {
            int wordId = selfCircleWordIdList[cur][0];
            dp[cur] += word2Len[wordId];
            wordNum[cur]++;
        }
        if (dp[cur] > maxCharNum) {
            maxCharNum = dp[cur];
            maxPos = cur;
        }
        if (tail != '\0' && cur == tail - 'a') {
            // maxCharNum = dp[cur];
            maxPos = cur;
            break;
        }
        for (Edge &e : g[cur]) {
            if (dp[e.to] < dp[cur] + word2Len[e.wordId]) {
                dp[e.to] = dp[cur] + word2Len[e.wordId];
                wordNum[e.to] = wordNum[cur] + 1;
                pre[e.to] = {cur, e.wordId};
            }
        }
    }
    // find the specific longest word chain with `maxPos` and `pre`
    int cur = maxPos;
    resultLen = wordNum[maxPos];
    for (int i = resultLen - 1; i >= 0; --i) {
        if (! selfCircleWordIdList[cur].empty()) {
            int wordId = selfCircleWordIdList[cur][0];
            result[i] = (char *) malloc((word2Len[wordId] + 1) * sizeof(char));
            strcpy(result[i], words[wordId]);
            --i;
        }
        int wordId = pre[cur].second;
        result[i] = (char *) malloc((word2Len[wordId] + 1) * sizeof(char));
        strcpy(result[i], words[wordId]);
    }

    return resultLen;
}
