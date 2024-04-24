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

TEST(SumResultInFrameTest, Strike) 
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

TEST(SumResultInFrameTest, Diapazone) 
{   
    vector<std::vector<int>> scoreVector = { 
        {15, 0}, // incorrect diapazone 
        {5, 3}, {4, 0}, {5, 0}, {8, 0}, 
        {1, 2}, {0, 0}, {4, 7}, {0, 0}, {0, 0}  
    };

    ASSERT_THROW(sumResultInFrame(scoreVector), runtime_error);

    vector<std::vector<int>> scoreVector2 = { 
        {0, 0}, {5, 3}, {4, 0}, {5, 0}, {8, 0}, 
        {1, 2}, {0, 0}, {4, 7}, {0, 0}, 
        {0, -6}  // incorrect diapazone
    };

    ASSERT_THROW(sumResultInFrame(scoreVector2), runtime_error);
}


TEST(SumResultInFrameTest, Spare) 
{   
    vector<std::vector<int>> scoreVector = { 
        {5, 5}, {5, 3}, // spare, scoreFrameVector[0] = 15
        {6, 4}, {9, 0}, // spare, scoreFrameVector[2] = 19
        {8, 2}, {10, 0}, // spare, scoreFrameVector[4] = 20
        {0, 0}, {4, 3}, 
        {3, 2}, {4, 6}  // last spare, scoreFrameVector[9] = 10
    };

    vector<int> scoreFrameVector = sumResultInFrame(scoreVector);
    
    EXPECT_EQ(scoreFrameVector[0], 15);
    EXPECT_EQ(scoreFrameVector[2], 19);
    EXPECT_EQ(scoreFrameVector[4], 20);
    EXPECT_EQ(scoreFrameVector[9], 10);
}

// default throw (i mean for example when u trow in firs 3 and second trow 5)
TEST(SumResultInFrameTest, DefaultThrow) 
{   
    vector<std::vector<int>> scoreVector = { 
        {0, 0}, {5, 3}, // default throw, scoreFrameVector[1] = 8
        {0, 0}, {9, 0}, // default throw, scoreFrameVector[3] = 9
        {0, 0}, {0, 5}, // default throw, scoreFrameVector[5] = 5
        {0, 0}, {4, 3}, // default throw, scoreFrameVector[7] = 7
        {0, 0}, {4, 4}  // last default throw, scoreFrameVector[9] = 8
    };

    vector<int> scoreFrameVector = sumResultInFrame(scoreVector);
    
    for (int i = 0; i < scoreFrameVector.size(); i += 2) {
        EXPECT_EQ(scoreFrameVector[i], 0);
    }

    EXPECT_EQ(scoreFrameVector[1], 8);
    EXPECT_EQ(scoreFrameVector[3], 9);
    EXPECT_EQ(scoreFrameVector[5], 5);
    EXPECT_EQ(scoreFrameVector[7], 7);
    EXPECT_EQ(scoreFrameVector[9], 8);
}