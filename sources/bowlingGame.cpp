#include <iostream>
#include "bowlingGame.h"

// set result
void BowlingGame::setResult(vector<vector<int>> vec) {
    scoreVector = vec;
}

// calculate scores in single frame vector<int>
void BowlingGame::sumResultInFrame() {
    vector<int> frameResData2(scoreVector.size());
    frameResData.resize(scoreVector.size());
    char message[100];

    for (int frameIndex = 0; frameIndex < scoreVector.size();) {

        /*
         * exception
         * correct diapazone is [0; 10]
         * if user use scores like [15][0] or [3][-1] throw exeption
         */
        if (scoreVector[frameIndex][0] < 0 || scoreVector[frameIndex][0] > 10
            || scoreVector[frameIndex][1] < 0 || scoreVector[frameIndex][1] > 10) {
            sprintf(message, "\nWrong entry! Incorrect diapazone, must be [0; 10], your diapazone is [%d; %d]\n",
                scoreVector[frameIndex][0], scoreVector[frameIndex][1]);
            throw runtime_error(message);
        }

        // strike
        if (scoreVector[frameIndex][0] == 10) {
            /*
             * exception for strike
             * correct stike in frame is [10][0]
             * if user use strike like [10][1] throw exeption
             */
            if (scoreVector[frameIndex][1] != 0) {
                sprintf(message, "\nWrong entry! Strike viewed like [10][0], your strike is [%d][%d]\n",
                    scoreVector[frameIndex][0], scoreVector[frameIndex][1]);
                throw runtime_error(message);
            }

            // if this is last strike, then write 10 and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = 10;
                break;
            }

            // default strike, write 10 and add score in next frame
            frameResData[frameIndex] = 10 + scoreVector[frameIndex + 1][0] + scoreVector[frameIndex + 1][1];

            // double strike
            if (scoreVector[frameIndex + 1][0] == 10) {

                // last double strike
                if (frameIndex + 1 == 9) {
                    frameResData[frameIndex] = 20;
                    // all strikes
                    if (scoreVector[frameIndex + 1][0] == 10) {
                        frameResData[frameIndex] = 30;
                        frameResData[frameIndex + 1] = 30;
                        break;
                    }
                    break;
                }

                frameResData[frameIndex] = 20 + scoreVector[frameIndex + 2][0];

            }

            // triple strike
            if (scoreVector[frameIndex + 1][0] == 10 && scoreVector[frameIndex + 2][0] == 10) {
                frameResData[frameIndex] = 30;
            }

            frameIndex++;
        }

        // spare
        else if (scoreVector[frameIndex][0] + scoreVector[frameIndex][1] == 10
            && scoreVector[frameIndex][1] != 0) {

            // if this is last spare, then sum in last frame 3 throws
            if (frameIndex == 9) {
                if (scoreVector[9][2] < 0 || scoreVector[9][2] > 10) {
                    sprintf(message, "\nWrong entry! Incorrect diapazone! Your last spare is [%d; /; %d]\n",
                        scoreVector[9][0], scoreVector[9][2]);
                    throw runtime_error(message);
                }

                frameResData[frameIndex] = 10 + scoreVector[9][2];
                break;
            }

            // default spare, write 10 and score for one trow in next frame
            frameResData[frameIndex] = 10 + scoreVector[frameIndex + 1][0];

            frameIndex++;

        }

        // default throw (i mean for example when u trow in firs 3 and second trow 5)
        else {

            if (scoreVector[frameIndex][0] + scoreVector[frameIndex][1] > 10) throw runtime_error("Error!");

            // if this is last throw, then write sum in last frame and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = scoreVector[frameIndex][0] + scoreVector[frameIndex][1];
                break;
            }

            // default throw, write sum this frame
            frameResData[frameIndex] = scoreVector[frameIndex][0] + scoreVector[frameIndex][1];

            frameIndex++;
        }
    }
}

// calculate total score
void BowlingGame::calcTotalScore() {
    totalScore = accumulate(frameResData.begin(), frameResData.end(), 0);
}

// print scores by frame 
void BowlingGame::paintResultByFrame() {

    cout << "\nFrame index:\n";
    for (int index = 0; index < 10; index++) {
        cout << index + 1 << "\t";
    }
    cout << "\nResult:\n";
    for (int index = 0; index < 10; index++) {
        cout << frameResData[index] << "\t";
    }
    cout << '\n';

}

// print total scores
void BowlingGame::paintTotalScore() {
    cout << "\nTotal score for all frames = " << totalScore << "\n";
}

// print all scores
void BowlingGame::paintAllThrows() {

    cout << "\nScore:\n";
    for (int frameIndex = 0; frameIndex < scoreVector.size(); frameIndex++) {
        for (int throwIndex = 0; throwIndex < scoreVector[0].size(); throwIndex++) {
            cout << scoreVector[frameIndex][throwIndex] << "\t";
        }
        if (scoreVector[frameIndex].size() == 3) {
            cout << scoreVector[9][2] << "\t";
        }
        cout << '\n';
    }
    cout << '\n';

}

// get result by frame (start index = 1)
int BowlingGame::getResultByFrame(int frameIndex) {
    return frameResData.at(frameIndex - 1);
}

// get result by throw in frame (start index = 1)
int BowlingGame::getResultByThrow(int frameIndex, int throwIndex) {
    return scoreVector.at(frameIndex - 1).at(throwIndex - 1);
}

int BowlingGame::getTotalScore() {
    return totalScore;
}