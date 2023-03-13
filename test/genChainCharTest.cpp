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
    char* expected[] = {
            "pseudopseudohypoparathyroidism",
            "moon"
    };

    char* result[100];
    int resultLen = gen_chain_char(words, len, result, '\0', '\0', '\0', false);
    ASSERT_EQ(resultLen, 2);

    std::sort(expected, expected + resultLen, my_cmp);
    std::sort(result, result + resultLen, my_cmp);

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
    char* expected[] = {
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

    std::sort(expected, expected + resultLen, my_cmp);
    std::sort(result, result + resultLen, my_cmp);

    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}