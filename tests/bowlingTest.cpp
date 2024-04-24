#include <gtest/gtest.h>
#include "bowlingGame.h"
#include "helpForTest.h"

TEST(ScoreForThrowTest, CorrectRange)
{   
    ASSERT_TRUE(checkSize(scoreForThrow(0, 10)));
}

TEST(ScoresVectorTest, CorrectSizeAndElements)
{   
    // our matrix with [10 frames][2 throws] and {scores}
    int scoresInMatrix[10][2] { 
    {1, 2}, {4, 5}, {10, 0}, {5, 5}, {9, 1}, 
    {5, 5}, {5, 5}, {4, 7}, {4, 5}, {4, 5} };

    vector<std::vector<int>> scoresInVector = scoreVector2(scoresInMatrix);

    ASSERT_EQ(scoresInVector.size(), 10);
    for (int i = 0; i < 10; ++i) {

        ASSERT_EQ(scoresInVector[i].size(), 2);
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(scoresInVector[i][j], scoresInMatrix[i][j]);
        }

    }
}

TEST(SumResultInFrameTest, StrikeTest) 
{   
vector<std::vector<int>> scoreVector = { 
    {10, 0}, {5, 3}, // strike, scoreFrameVector[0] = 18
    {10, 0}, {10, 0}, {10, 0}, // tripple strike, scoreFrameVector[2] = 30
    {1, 2}, {0, 0}, {4, 7}, {0, 0}, 
    {10, 0}  // last strike, scoreFrameVector[9] = 10
    }; 

    vector<int> scoreFrameVector = sumResultInFrame(scoreVector);

    EXPECT_EQ(scoreFrameVector[0], 18);
    EXPECT_EQ(scoreFrameVector[2], 30);
    EXPECT_EQ(scoreFrameVector[3], 20);
    EXPECT_EQ(scoreFrameVector[4], 13);
    EXPECT_EQ(scoreFrameVector[9], 10);
}


