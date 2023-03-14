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

TEST(genChainChar, genChainCharTest5) {
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
    int resultLen = gen_chain_char(words, wordsLen, result, 'e', '\0', '\0', false);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest6) {
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
    int resultLen = gen_chain_char(words, wordsLen, result, '\0', 't', '\0', false);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest7) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "teach",
            "talk"
    };
    const char* expected[] = {
            "element",
            "tot",
            "tight",
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

TEST(genChainChar, genChainCharTest8) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "teach",
            "talk"
    };
    const char* expected[] = {
            "tot",
            "tight",
            "teach",
            "heaven",
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_char(words, wordsLen, result, 't', '\0', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest9) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "teach",
            "talk"
    };
    const char* expected[] = {
            "element",
            "tot",
            "tight",
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_char(words, wordsLen, result, '\0', 't', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest10) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "teach",
            "talk"
    };
    const char* expected[] = {
            "element",
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_char(words, wordsLen, result, '\0', '\0', 't', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainChar, genChainCharTest11) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "teach",
            "talk"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    char* result[100];
    try {
        gen_chain_char(words, wordsLen, result, '\0', '\0', '\0', false);
        FAIL();
    } catch (const std::logic_error& e) {
        ASSERT_STREQ(e.what(), "Circle detected");
    } catch (...) {
        FAIL();
    }
}