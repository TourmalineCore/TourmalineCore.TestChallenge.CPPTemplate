#include <gtest/gtest.h>
#include "example.h"

// help func, count in one trow must be [0; 10]
bool checkSize(int count) {
    if (count < 0 || count > 10) return false;
    return true;
}

TEST(TestTrow, TrowScoreTest)
{   
    ASSERT_TRUE(checkSize(scoreForThrow(0, 10)));
}

TEST(TestScoresVector, TestSizeAndElements)
{   
    // our matrix with [10 frames][2 throws] and {scores}
    int scoresForThrows[10][2] { 
    {1, 2}, {4, 5}, {10, 0}, {5, 5}, {9, 1}, 
    {5, 5}, {5, 5}, {4, 7}, {4, 5}, {4, 5} };

    vector<std::vector<int>> resData = scoreVector2(scoresForThrows);

    ASSERT_EQ(resData.size(), 10);
    for (int i = 0; i < 10; ++i) {

        ASSERT_EQ(resData[i].size(), 2);
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(resData[i][j], scoresForThrows[i][j]);
        }

    }
}

TEST(SumResultInFrameTest, StrikeTest) 
{   
vector<std::vector<int>> resData2 = { 
    {10, 0}, {5, 3}, // correct strike result = 18
    {0, 10}, {5, 5}, // correct strike result = 20
    {10, 1}, {5, 5}, // incorrect strike frame {10, 1} have 11 score, but max is 10
    {15, 0}, {4, 7}, // incorrect strike
    {0, 0}, {10, 0}  // correct last strike
    }; 

    vector<int> frameResData = sumResultInFrame(resData2);

    EXPECT_EQ(frameResData[0], 18); // ok
    EXPECT_EQ(frameResData[2], 20); // ok
    EXPECT_EQ(frameResData[4], 28); // error
    EXPECT_EQ(frameResData[6], 20); // error
    EXPECT_EQ(frameResData[9], 30); // ok
}


