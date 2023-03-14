#include "test.h"


TEST(genChainWord, genChainWordTest1) {
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
            "algebra",
            "apple",
            "elephant",
            "trick"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);

    char* result[100];
    int resultLen = gen_chain_word(words, wordsLen, result, '\0', '\0', '\0', false);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}


TEST(genChainWord, genChainWordTest2) {
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
            "elephant",
            "trick"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_word(words, wordsLen, result, 'e', '\0', '\0', false);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainWord, genChainWordTest3) {
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
            "algebra",
            "apple" ,
            "elephant",
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_word(words, wordsLen, result, '\0', 't', '\0', false);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainWord, genChainWordTest4) {
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
            "elephant",
            "trick"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_word(words, wordsLen, result, '\0', '\0', 'a', false);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainWord, genChainWordTest5) {
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
    int resultLen = gen_chain_word(words, wordsLen, result, '\0', '\0', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}
