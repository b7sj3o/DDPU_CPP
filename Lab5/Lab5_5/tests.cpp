#include <gtest/gtest.h>
#include "main.cpp"

TEST(FunctionTest, TestMethod1) {
    EXPECT_EQ(NCD(125, 20), 5);
    // EXPECT_EQ(NCD(56, 98), 14);
    // EXPECT_EQ(NCD(15, 0), 15);
    // EXPECT_EQ(NCD(0, 20), 20);
    // EXPECT_EQ(NCD(7, 1), 1);

}

int test_main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
