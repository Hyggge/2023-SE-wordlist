#ifndef WORDLIST_SOLVER_H
#define WORDLIST_SOLVER_H

int genChainsAllWithoutCircle(char* words[], int len, char* result[]);

int genChainsAllWithCircle(char* words[], int len, char* result[]);

int genChainWordWithoutCircle(char* words[], int len, char* result[], char head, char tail, char except);

int genChainWordWithCircle(char* words[], int len, char* result[], char head, char tail, char except);

int genChainCharWithoutCircle(char* words[], int len, char* result[], char head, char tail, char except);

int genChainCharWithCircle(char* words[], int len, char* result[], char head, char tail, char except);

#endif //WORDLIST_SOLVER_H