#ifndef WORDLIST_CORE_H
#define WORDLIST_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

int gen_chains_all(char* words[], int len, char* result[]);

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop);

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop);

#ifdef __cplusplus
}
#endif
#endif //WORDLIST_CORE_H