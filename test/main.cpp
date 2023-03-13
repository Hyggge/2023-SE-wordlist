#include <gtest/gtest.h>
#include "Core.h"

TEST(genChainsAll, genChainsAllTest1) {
    int len = 4;
    char* words[] = {"woo", "oom", "moon", "noox"};
    char* result[100];
    char* expected[] = {
            "woo oom",
            "moon noox",
            "oom moon",
            "woo oom moon",
            "oom moon noox",
            "woo oom moon noox"
    };
    int resultLen = gen_chains_all(words, len, result);
    ASSERT_EQ(resultLen, 6);
    for (int i = 0; i < 6; ++i) {
        ASSERT_EQ(result[i], expected[i]);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}