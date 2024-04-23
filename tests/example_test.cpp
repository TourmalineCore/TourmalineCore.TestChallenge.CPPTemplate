#include <gtest/gtest.h>
#include "example.h"

// help func, count in one trow must be [0; 10]
bool checkSize(int count) {
    if (count < 0 || count > 10) return false;
    return true;
}

TEST(TestTrow, TrowScoreTest)
{   
    ASSERT_TRUE(checkSize(scoreForTrow(0, 10)));
}

TEST(TestTrow2, TrowScoreTest2)
{   
    int scoresForTrows[10][2] { 
    {1, 2}, {4, 5}, {10, 0}, {5, 5}, {9, 1}, 
    {5, 5}, {5, 5}, {4, 7}, {4, 5}, {4, 5} };

    vector<std::vector<int>> resData = scoreVector2(scoresForTrows);

    ASSERT_EQ(resData.size(), 10);
    for (int i = 0; i < 10; ++i) {

        ASSERT_EQ(resData[i].size(), 2);
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(resData[i][j], scoresForTrows[i][j]);
        }

    }
}