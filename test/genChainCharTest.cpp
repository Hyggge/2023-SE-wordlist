#include "test.h"


TEST(genChainChar, genChainCharTest1) {
    int len = 11;
    char* words[] = {"algebra",
                     "apple" ,
                     "zoo",
                     "elephant",
                     "under",
                     "fox",
                     "dog",
                     "moon",
                     "leaf",
                     "trick",
                     "pseudopseudohypoparathyroidism"
    };
    const char* expected[] = {
            "pseudopseudohypoparathyroidism",
            "moon"
    };

    char* result[100];
    int resultLen = gen_chain_char(words, len, result, '\0', '\0', '\0', false);
    ASSERT_EQ(resultLen, 2);
    for (int i = 0; i < 2; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest2) {
    char* words[] = {
            "element",
            "heaven",
            "table",
            "teach",
            "talk"
    };
    const char* expected[] = {
            "table",
            "element",
            "teach",
            "heaven",
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_char(words, wordsLen, result, '\0', '\0', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest3) {
    char* words[] = {"aa", "ab", "bb", "bc", "cc", "cd", "dd"};
    const char* expected[] = {"aa", "ab", "bb", "bc", "cc", "cd", "dd"};
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_char(words, wordsLen, result, '\0', '\0', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest4) {
    char* words[] = {"aa", "ab", "bb", "bc", "cc", "cd"};
    const char* expected[] = {"aa", "ab", "bb", "bc", "cc", "cd"};
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_char(words, wordsLen, result, '\0', '\0', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}