#include <gtest/gtest.h>
#include "test.h"

bool my_cmp(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}