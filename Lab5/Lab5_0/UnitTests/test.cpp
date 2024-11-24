// used google tests instead of <CppUnitTest> because it works better for linux os.
#include <gtest/gtest.h>
#include "../Lab5_1/main.cpp"

TEST(FunctionTest, TestMethod1) {
    double x = 5.0;
    double y = 6.0;

    double part1 = squared_nums(x * y, pow(x, 2), pow(y, 2));
    double part2 = squared_nums(1, x, y);
    double part3 = squared_nums(sqrt(x), pow(y, 2), 1);

    double result = (part1 - pow(part2, 2)) / 1 + part3;

    EXPECT_DOUBLE_EQ(result, 279.0);
}

int test_main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
