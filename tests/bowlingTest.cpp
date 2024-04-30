#include <gtest/gtest.h>
#include "bowlingGame.h"
#include "helpForTest.h"

class Strike : public testing::Test {
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

    void SetUpSecond() {
        vector <vector <int>> resData {
        {10, 0}, {6, 2}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 0}, {10, 0} };
        game -> setResult(resData);
        game -> sumResultInFrame();
    }

    void SetUpThird() {
        vector <vector <int>> resData {
        {10, 0}, {10, 0}, {5, 1}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {10, 0}, {10, 0} };
        game -> setResult(resData);
        game -> sumResultInFrame();
    }

    void SetUpFourth() {
        vector <vector <int>> resData {
        {10, 0}, {10, 0}, {10, 0}, {5, 3}, {0, 0},
        {0, 0}, {0, 0}, {10, 0}, {10, 0}, {10, 0} };
        game -> setResult(resData);
        game -> sumResultInFrame();
    }

    void TearDown() override {
        delete game;
    }
};

TEST_F(Strike, AllStrikeCorrectTotalScore) {   
    EXPECT_EQ(game -> getTotalScore(), 300);
}

TEST_F(Strike, AllStrikeCorrectResultByFrames) {
    vector<int> expecFrameResData {30, 30, 30, 30, 30, 30, 30, 30, 30, 30};
    EXPECT_EQ(game -> getFrameResData(), expecFrameResData);
}

TEST_F(Strike, CorrectScore) {
    SetUpSecond();
    EXPECT_EQ(game -> getResultByFrame(1), 18);
}

TEST_F(Strike, LastStrikeCorrectScore) {
    SetUpSecond();
    EXPECT_EQ(game -> getResultByFrame(10), 10);
}

TEST_F(Strike, DoubleStrikeCorrectScore) {
    SetUpThird();
    EXPECT_EQ(game -> getResultByFrame(1), 25);
    EXPECT_EQ(game -> getResultByFrame(2), 16);

}

TEST_F(Strike, TripleStrikeCorrectScore) {
    SetUpFourth();
    EXPECT_EQ(game -> getResultByFrame(1), 30);
    EXPECT_EQ(game -> getResultByFrame(2), 25);
    EXPECT_EQ(game -> getResultByFrame(3), 18);
}

TEST_F(Strike, LastTripleStrikeCorrectScore) {
    SetUpFourth();
    EXPECT_EQ(game -> getResultByFrame(8), 30);
    EXPECT_EQ(game -> getResultByFrame(9), 20);
    EXPECT_EQ(game -> getResultByFrame(10), 10);
}

class Spare : public testing::Test {
protected: BowlingGame *game;

    void SetUp() {
        game = new BowlingGame();
        vector <vector <int>> resData {
        {5, 5}, {7, 3}, {7, 2}, {9, 1}, {0, 10},
        {4, 2}, {0, 10}, {2, 3}, {6, 4}, {7, 3, 3} };
        game -> setResult(resData);
        game -> sumResultInFrame();
        game -> calcTotalScore();
    }

    void SetUpSecond() {
        vector <vector <int>> resData {
        {5, 5}, {7, 3}, {7, 2}, {9, 1}, {0, 10},
        {4, 2}, {0, 10}, {2, 3}, {6, 4}, {7, 3} }; // last frame without additional throw on 10 pins
        game -> setResult(resData);
    }

    void SetUpThird() {
        vector <vector <int>> resData {
        {5, 10}, {7, 3}, {7, 2}, {9, 1}, {0, 10},
        {4, 2}, {0, 10}, {2, 3}, {6, 4}, {7, 2} }; // second throw in first frame have broken score
        game -> setResult(resData);
    }

    void TearDown() override {
        delete game;
    }
};

TEST_F(Spare, CorrectTotalScore) {
    EXPECT_EQ(game -> getTotalScore(), 120);
}

TEST_F(Spare, CorrectResultByFrames) {
    EXPECT_EQ(game -> getResultByFrame(1), 17);
    EXPECT_EQ(game -> getResultByFrame(2), 17);
    EXPECT_EQ(game -> getResultByFrame(3), 9);
    EXPECT_EQ(game -> getResultByFrame(4), 10);
    EXPECT_EQ(game -> getResultByFrame(5), 14);
    EXPECT_EQ(game -> getResultByFrame(6), 6);
    EXPECT_EQ(game -> getResultByFrame(7), 12);
    EXPECT_EQ(game -> getResultByFrame(8), 5);
    EXPECT_EQ(game -> getResultByFrame(9), 17);
    EXPECT_EQ(game -> getResultByFrame(10), 13);
}

TEST_F(Spare, IncorrectEntryInLastFrame) {
    SetUpSecond();
    EXPECT_THROW(game -> sumResultInFrame(), runtime_error);
}

TEST_F(Spare, IncorrectDiapazoneInFrame) {
    SetUpThird();
    EXPECT_THROW(game -> sumResultInFrame(), runtime_error);
}

class DefaultThrow : public testing::Test {
protected: BowlingGame *game;

    void SetUp() {
        game = new BowlingGame();
        vector <vector <int>> resData {
        {5, 2}, {1, 3}, {7, 2}, {5, 1}, {3, 3},
        {1, 0}, {0, 8}, {2, 3}, {2, 2}, {5, 1} };
        game -> setResult(resData);
        game -> sumResultInFrame();
        game -> calcTotalScore();
    }

    void SetUpSecond() {
        vector <vector <int>> resData {
        {5, 2}, {1, 3}, {7, 4}, {5, 1}, {3, 3},
        {1, 0}, {0, 8}, {2, 3}, {2, 2}, {5, 1} }; // second throw in third frame have broken score
        game -> setResult(resData);
    }

    void SetUpThird() {
        vector <vector <int>> resData {
        {5, 2, 5}, {1, 3}, {0, 4}, {5, 1}, {3, 3},
        {1, 0}, {0, 8}, {2, 3}, {2, 2}, {5, 1} }; // in first frame have more than 2 throws
        game -> setResult(resData);
    }

    void TearDown() override {
        delete game;
    }
};

TEST_F(DefaultThrow, CorrectTotalScore) {
    EXPECT_EQ(game -> getTotalScore(), 56);
}

TEST_F(DefaultThrow, CorrectResultByFrames) {
    EXPECT_EQ(game -> getResultByFrame(1), 7);
    EXPECT_EQ(game -> getResultByFrame(2), 4);
    EXPECT_EQ(game -> getResultByFrame(3), 9);
    EXPECT_EQ(game -> getResultByFrame(4), 6);
    EXPECT_EQ(game -> getResultByFrame(5), 6);
    EXPECT_EQ(game -> getResultByFrame(6), 1);
    EXPECT_EQ(game -> getResultByFrame(7), 8);
    EXPECT_EQ(game -> getResultByFrame(8), 5);
    EXPECT_EQ(game -> getResultByFrame(9), 4);
    EXPECT_EQ(game -> getResultByFrame(10), 6);
}

TEST_F(DefaultThrow, IncorrectDiapazoneInFrame) {
    SetUpSecond();
    EXPECT_THROW(game -> sumResultInFrame(), runtime_error);
}

TEST_F(DefaultThrow, IncorrectCountOfThrowInFrame) {
    SetUpThird();
    EXPECT_THROW(game -> sumResultInFrame(), runtime_error);
}

class PersonalGame : public testing::Test {
protected: BowlingGame *game;

    void SetUp() {
        game = new BowlingGame();
        vector <vector <int>> resData {
        {10, 0}, {7, 3}, {7, 2}, {9, 1}, {10, 0},
        {10, 0}, {10, 0}, {2, 3}, {6, 4}, {7, 3, 3} };
        game -> setResult(resData);
        game -> sumResultInFrame();
        game -> calcTotalScore();
    }

    void SetUpSecond() {
        vector <vector <int>> resData {
        {10, 0}, {3, 3} };
        game -> setResult(resData);
    }

    void SetUpThird() {
        vector <vector <int>> resData {
        {10, 0}, {33, 3}, {7, 2}, {9, 1}, {4, 0},
        {1000, 0}, {10, 0}, {2, 3}, {20, 4}, {7, 3, 0} };
        game -> setResult(resData);
    }

    void SetUpFourth() {
        vector <vector <int>> resData {
        {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
        game -> setResult(resData);
        game -> sumResultInFrame();
        game -> calcTotalScore();
    }

    void TearDown() override {
        delete game;
    }
};

TEST_F(PersonalGame, CorrectTotalScore) {
    EXPECT_EQ(game -> getTotalScore(), 168);
}

TEST_F(PersonalGame, CorrectResultByFrames) {
    EXPECT_EQ(game -> getResultByFrame(1), 20);
    EXPECT_EQ(game -> getResultByFrame(2), 17);
    EXPECT_EQ(game -> getResultByFrame(3), 9);
    EXPECT_EQ(game -> getResultByFrame(4), 20);
    EXPECT_EQ(game -> getResultByFrame(5), 30);
    EXPECT_EQ(game -> getResultByFrame(6), 22);
    EXPECT_EQ(game -> getResultByFrame(7), 15);
    EXPECT_EQ(game -> getResultByFrame(8), 5);
    EXPECT_EQ(game -> getResultByFrame(9), 17);
    EXPECT_EQ(game -> getResultByFrame(10), 13);
}

TEST_F(PersonalGame, IncorrectCountOfFrame) {
    SetUpSecond();
    EXPECT_THROW(game -> sumResultInFrame(), runtime_error);
}

TEST_F(PersonalGame, IncorrectScoreInFrame) {
    SetUpThird();
    EXPECT_THROW(game -> sumResultInFrame(), runtime_error);
}

TEST_F(PersonalGame, AllZeroesCorrectTotalScore) {
    SetUpFourth();
    EXPECT_EQ(game -> getTotalScore(), 0);
}

TEST_F(PersonalGame, AllZeroesCorrectScoreByFrames) {
    SetUpFourth();
    vector<int> expecFrameResData {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(game -> getFrameResData(), expecFrameResData);
}