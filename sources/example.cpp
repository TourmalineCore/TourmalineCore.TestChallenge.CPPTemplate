#include <iostream>
#include "example.h"

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

    for (int frameIndex = 0, throwIndex = 0; frameIndex < 10;) {

        // strike
        if (scoreVector[frameIndex][throwIndex] == 10) {

            // if this is last strike, then write 10 and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = 10;
                break;
            }

            // default strike, write 10 and add score in next frame
            frameResData[frameIndex] = 10 + scoreVector[frameIndex + 1][throwIndex] + scoreVector[frameIndex + 1][throwIndex + 1];

            // triple strike
            if (scoreVector[frameIndex + 1][throwIndex] == 10 && scoreVector[frameIndex + 2][throwIndex] == 10) {
                frameResData[frameIndex] = 30;
            }

            frameIndex++;

        }

        // spare
        else if (scoreVector[frameIndex][throwIndex] + scoreVector[frameIndex][throwIndex + 1] == 10 
        && scoreVector[frameIndex][throwIndex + 1] != 0) {

            // if this is last spare, then write 10 and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = 10;
                break;
            }

            // default spare, write 10 and score for one trow in next frame
            frameResData[frameIndex] = 10 + scoreVector[frameIndex + 1][throwIndex];

            frameIndex++;

        }

        // default throw
        else {

            // if this is last throw, then write sum in last frame and break
            if (frameIndex == 9) {
                frameResData[frameIndex] = scoreVector[frameIndex][throwIndex] + scoreVector[frameIndex][throwIndex + 1];
                break;
            }

            // default throw, write sum this frame
            frameResData[frameIndex] = scoreVector[frameIndex][throwIndex] + scoreVector[frameIndex][throwIndex + 1];

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