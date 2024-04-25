#include <gtest/gtest.h>
#include "bowlingGame.h"
#include "helpForTest.h"

TEST(ScoreForThrowTest, CorrectRange)
{   
    ASSERT_TRUE(checkSize(scoreForThrow(0, 10)));
}

TEST(SumResultInFrameTest, Strike) 
{   
    vector<std::vector<int>> scoreVector = { 
        {10, 0}, {5, 3}, // strike, scoreFrameVector[0] = 18
        {10, 0}, {10, 0}, {10, 0}, // tripple strike, scoreFrameVector[2] = 30
        {1, 2}, {0, 0}, {4, 6}, {0, 0}, 
        {10, 0}  // last strike, scoreFrameVector[9] = 10
    }; 

    vector<int> scoreFrameVector = sumResultInFrame(scoreVector);
    EXPECT_EQ(scoreFrameVector[0], 18);
    EXPECT_EQ(scoreFrameVector[2], 30);
    EXPECT_EQ(scoreFrameVector[3], 21); // double strike
    EXPECT_EQ(scoreFrameVector[4], 13);
    EXPECT_EQ(scoreFrameVector[9], 10);
    
}

TEST(SumResultInFrameTest, Diapazone) 
{   
    vector<std::vector<int>> scoreVector = { 
        {15, 0}, // incorrect diapazone 
        {5, 3}, {4, 0}, {5, 0}, {8, 0}, 
        {1, 2}, {0, 0}, {4, 6}, {0, 0}, {0, 0}  
    };

    ASSERT_THROW(sumResultInFrame(scoreVector), runtime_error);

    vector<std::vector<int>> scoreVector2 = { 
        {0, 0}, {5, 3}, {4, 0}, {5, 0}, {8, 0}, 
        {1, 2}, {0, 0}, {4, 6}, {0, 0}, 
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

    EXPECT_EQ(scoreFrameVector[1], 8);
    EXPECT_EQ(scoreFrameVector[3], 9);
    EXPECT_EQ(scoreFrameVector[5], 5);
    EXPECT_EQ(scoreFrameVector[7], 7);
    EXPECT_EQ(scoreFrameVector[9], 8);

    // check unlucky trow wich {0, 0}
    for (int i = 0; i < scoreFrameVector.size(); i += 2) {
        EXPECT_EQ(scoreFrameVector[i], 0);
    }
}

TEST(TotalScoreTest, AmountScored) 
{   
    vector<std::vector<int>> scoreVector = { 
        {10, 0}, {5, 3}, 
        {5, 5}, {9, 1},
        {4, 3}, {0, 5},
        {0, 0}, {4, 3},
        {0, 0}, {10, 0}  
    };

    /* 
     * scores for frame: 1f = 18; 2f = 8; 3f = 19; 4f = 14;
     * 5f = 7; 6f = 6; 7f = 0; 8f = 7; 9f = 0; 10f = 10.
     * total scores for all frames = 88
     */

    vector<int> scoreFrameVector = sumResultInFrame(scoreVector);

    EXPECT_EQ(totalScore(scoreFrameVector), 88);
}

TEST(PaintTest, NoErrorAndException) 
{   
    // create our vector with downed pins by frame
    vector <vector <int>> resData{
    {10, 0}, {7, 3}, {7, 2}, {9, 1}, {10, 0},
    {10, 0}, {10, 0}, {2, 3}, {6, 4}, {7, 3, 3} };

    paint(resData, 1, 4);

    // sum res by frames
    vector<int> scoresByFrames = sumResultInFrame(resData);

    paint(scoresByFrames, 1);

    // calc total score
    int totalScores =  totalScore(scoresByFrames);

    ASSERT_NO_THROW(paint(resData));
    ASSERT_NO_THROW(paint(scoresByFrames));
    ASSERT_NO_THROW(paint(totalScores));

    ASSERT_NO_FATAL_FAILURE(paint(resData));
    ASSERT_NO_FATAL_FAILURE(paint(scoresByFrames));
    ASSERT_NO_FATAL_FAILURE(paint(totalScores));
}