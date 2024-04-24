#include <iostream>
#include "bowlingGame.h"

/* 
 * calculate count score of downed pins
 * return any number from range [startRange; endRange]
 */ 
int scoreForThrow(int startRange, int endRange) {
    srand(time(NULL)); // Initializing pseudorandom number generator
    int x = rand() % (endRange - startRange + 1) + startRange; 
    return x;
}

// func for writing down result of throws v1
vector<vector<int>> scoreVector() {
    
    int startRange = 0;
    int endRange = 10;
    vector <vector <int>> resData (10, vector <int>(2));

    for (int frameIndex = 0; frameIndex < 10; frameIndex++) {

        int scoreCount = scoreForThrow(startRange, endRange); // [0; 10]

        for (int throwIndex = 0; throwIndex < 2; throwIndex++) {   

            // write strike
            if (scoreCount == 10) {
                resData[frameIndex][throwIndex] = 10;
                resData[frameIndex][throwIndex + 1] = 0;
                break;
            }

            // write other results
            else if (throwIndex == 1) { // second trow
                
                resData[frameIndex][throwIndex] = scoreForThrow(startRange, endRange - scoreCount); // [0; 10 - first trow]
            }
            else { // first trow
                resData[frameIndex][throwIndex] = scoreCount;
            }

        }

    }

    return resData;
}

// func for writing down result of throws v2
vector<vector<int>> scoreVector2(int data[10][2]) {

    vector <vector <int>> resData (10, vector <int>(2));
              
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            resData[i][j] = data[i][j];
        }
    }
    
    return resData;
}

// func calculate scores in single frame
vector<int> sumResultInFrame(vector<vector<int>> scoreVector) {

    vector<int> frameResData(10);
    char message[100];

    for (int frameIndex = 0; frameIndex < 10;) {
        
        /* 
         * exception
         * correct diapazone is [0; 10]
         * if user use scores like [15][0] or [3][-1] throw exeption
         */ 
        if (scoreVector[frameIndex][0] < 0 || scoreVector[frameIndex][0] > 10 
        || scoreVector[frameIndex][1] < 0 || scoreVector[frameIndex][1] > 10) {
            sprintf(message, "\nWrong entry! Incorrect diapazone, must be [0; 10], your diapazone is [%d; %d]\n", 
            scoreVector[frameIndex][0], scoreVector[frameIndex][1]);
            throw runtime_error (message);
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
                throw runtime_error (message);
            }

            // if this is last strike, then write 10 and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = 10;
                break;
            }

            // default strike, write 10 and add score in next frame
            frameResData[frameIndex] = 10 + scoreVector[frameIndex + 1][0] + scoreVector[frameIndex + 1][1];

            // triple strike
            if (scoreVector[frameIndex + 1][0] == 10 && scoreVector[frameIndex + 2][0] == 10) {
                frameResData[frameIndex] = 30;
            }

            frameIndex++;

        }

        // spare
        else if (scoreVector[frameIndex][0] + scoreVector[frameIndex][1] == 10 
        && scoreVector[frameIndex][1] != 0) {

            // if this is last spare, then write 10 and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = 10;
                break;
            }

            // default spare, write 10 and score for one trow in next frame
            frameResData[frameIndex] = 10 + scoreVector[frameIndex + 1][0];

            frameIndex++;

        }

        // default throw (i mean for example when u trow in firs 3 and second trow 5)
        else {

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

    return frameResData;
}

void paint(vector<int> sumResultInFrame) {

    cout << "\nFrame index:\n";
    for (int index = 0; index < 10; index++) {
        cout << index + 1 << "\t";
    }
    cout << "\nResult:\n";
    for (int index = 0; index < 10; index++) {
        cout << sumResultInFrame[index] << "\t";
    }
    cout << '\n';

}

void paint(vector<vector<int>> scoreVector) {

    cout << "\nScore:\n";
    for (int frameIndex = 0; frameIndex < scoreVector.size(); frameIndex++) {
        for (int throwIndex = 0; throwIndex < scoreVector[0].size(); throwIndex++) {
            cout << scoreVector[frameIndex][throwIndex] << "\t";
        }
        cout << '\n';
    }
    cout << '\n';

}