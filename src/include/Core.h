#ifndef WORDLIST_CORE_H
#define WORDLIST_CORE_H

#ifdef DLL_EXPORT
#define DLL_FUNC __declspec(dllexport)
#else
#define DLL_FUNC __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLL_FUNC int gen_chains_all(char* words[], int len, char* result[]);

DLL_FUNC int gen_chain_word(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop);

DLL_FUNC int gen_chain_char(char* words[], int len, char* result[], char head, char tail, char except, bool enable_loop);

#ifdef __cplusplus
}
#endif
#endif //WORDLIST_CORE_H