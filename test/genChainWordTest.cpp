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

TEST(genChainWord, genChainWordTest6) {
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
    int resultLen = gen_chain_word(words, wordsLen, result, 't', '\0', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainWord, genChainWordTest7) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "new",
            "teach",
            "talk",
            "knight",
            "tough",
            "not"
    };
    // answer:  element tot tight talk knight teach heaven new
    // longest: element tot tight talk knight teach heaven not tough
    const char* expected[] = {
            "element",
            "tot",
            "tight",
            "talk",
            "knight",
            "teach",
            "heaven",
            "new"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_word(words, wordsLen, result, '\0', 'w', '\0', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainWord, genChainWordTest8) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "new",
            "teach",
            "talk",
            "knight",
            "tough",
            "not"
    };
    const char* expected[] = {
            "heaven",
            "new"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chain_word(words, wordsLen, result, '\0', '\0', 't', true);
    ASSERT_EQ(resultLen, expectedLen);
    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainWord, genChainWordTest9) {
    char* words[] = {
            "element",
            "heaven",
            "tot",
            "tight",
            "new",
            "teach",
            "talk",
            "knight",
            "tough",
            "not"
    };
    int wordsLen = sizeof(words) / sizeof(words[0]);
    char* result[100];
    try {
        gen_chain_word(words, wordsLen, result, '\0', '\0', '\0', false);
        FAIL();
    } catch (const std::logic_error& e) {
        ASSERT_STREQ(e.what(), "Circle detected");
    } catch (...) {
        FAIL();
    }
}

TEST(genChainWord, genChainWordTest10) {
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
        gen_chain_word(words, wordsLen, result, '\0', '\0', 't', false);
        FAIL();
    } catch (const std::logic_error& e) {
        ASSERT_STREQ(e.what(), "Circle detected");
    } catch (...) {
        FAIL();
    }
}