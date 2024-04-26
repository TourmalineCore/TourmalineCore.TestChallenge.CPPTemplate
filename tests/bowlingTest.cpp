#include <gtest/gtest.h>
#include "bowlingGame.h"
#include "helpForTest.h"

class AllStrike : public testing::Test {
protected: BowlingGame *game;

    void SetUp() override {
        game = new BowlingGame();
        vector <vector <int>> resData {
        {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
        {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0} };
        game -> setResult(resData);
        game -> sumResultInFrame();
        game -> calcTotalScore();
    }

    void TearDown() override {
        delete game;
    }
};

TEST_F(AllStrike, CorrectTotalScore)
{   
    EXPECT_EQ(game -> getTotalScore(), 300);
}
