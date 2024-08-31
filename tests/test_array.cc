#include <gtest/gtest.h>
#include "array.h"


TEST(ArrayTest, DefaultConstructor) {
    Ariana::Array<int> x;
}

TEST(ArrayTest, InitializerListConstructor) {

}

TEST(ArrayTest, CopyConstructor) {

}

TEST(ArrayTest, AssignmentOperator) {

}

TEST(ArrayTest, Iterator) {
    Ariana::Array<int> arr = {10, 20, 30};
    
    auto it = arr.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
    ++it;
    EXPECT_EQ(*it, arr.end());
}

TEST(ArrayTest, RangeBasedLoop) {
    Ariana::Array<int> arr = {10, 20, 30};

    int expected[3] = {10, 20, 30};

    int index = 0;
    for (int value: arr) {
        EXPECT_EQ(value, expected[index++]);
    }
}