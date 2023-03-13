#include "test.h"


TEST(genChainsAll, genChainsAllTest1) {
    int len = 4;
    char* words[] = {"woo", "oom", "moon", "noox"};
    char* expected[] = {
            "woo oom",
            "moon noox",
            "oom moon",
            "woo oom moon",
            "oom moon noox",
            "woo oom moon noox"
    };

    char* result[100];
    int resultLen = gen_chains_all(words, len, result);
    ASSERT_EQ(resultLen, 6);

    std::sort(expected, expected + resultLen, my_cmp);
    std::sort(result, result + resultLen, my_cmp);

    for (int i = 0; i < 6; ++i) {
    ASSERT_STREQ(result[i], expected[i]);
    }
}
