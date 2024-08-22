#include <gtest/gtest.h>
#include "stack.h"

TEST(StackTest, PushElemenets) {
    Ariana::Stack<int> stack;
    stack.push(10);
    stack.push(20);

    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), 20);
}

TEST(StackTest, PopElements) {
    Ariana::Stack<int> stack;
    stack.push(10);
    stack.push(20);

    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 10);

    stack.pop();
    EXPECT_EQ(stack.size(), 0);
    EXPECT_TRUE(stack.empty());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}