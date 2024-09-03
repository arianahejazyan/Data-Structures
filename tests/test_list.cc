#include <gtest/gtest.h>
#include "list.h"

TEST(ListTest, DefaultConstructor) {

    Ariana::List<int> list;

    EXPECT_TRUE(list.empty());
}

TEST(ListTest, PushFront) {

    Ariana::List<int> list;

    list.push_front(10);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 1);

    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 2);

    list.push_front(30);
    EXPECT_EQ(list.front(), 30);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 3);
}

TEST(ListTest, PushBack) {
  
    Ariana::List<int> list;

    list.push_back(10);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 1);

    list.push_back(20);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
    EXPECT_EQ(list.size(), 2);

    list.push_back(30);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 30);
    EXPECT_EQ(list.size(), 3);  
}

TEST(ListTest, PopFront) {
    
    Ariana::List<int> list;

    list.push_front(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_front();
    EXPECT_EQ(list.front(), 20);
    EXPECT_EQ(list.back(), 30);
    EXPECT_EQ(list.size(), 2);

    list.pop_front();
    EXPECT_EQ(list.front(), 30);
    EXPECT_EQ(list.back(), 30);
    EXPECT_EQ(list.size(), 1);  

    list.pop_front();
    EXPECT_TRUE(list.empty());  
}

TEST(ListTest, PopBack) {
        
    Ariana::List<int> list;

    list.push_front(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_back();
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
    EXPECT_EQ(list.size(), 2);

    list.pop_back();
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 1);  

    list.pop_back();
    EXPECT_TRUE(list.empty());  
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}