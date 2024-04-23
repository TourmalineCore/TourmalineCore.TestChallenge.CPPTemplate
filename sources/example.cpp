#include <iostream>
#include "example.h"

/* 
 * calculate count score of downed pins
 * return any number from range [startRange; endRange]
 */ 
int scoreForTrow(int startRange, int endRange) {
    //srand(time(NULL)); // Initializing pseudorandom number generator
    int x = rand() % (endRange - startRange + 1) + startRange; 
    return x;
}

// func for writing down result of throws v1
vector<vector<int>> scoreVector() {
    
    int startRange = 0;
    int endRange = 10;
    vector <vector <int>> resData (10, vector <int>(2));

    for (int frameIndex = 0; frameIndex < 10; frameIndex++) {

        int scoreCount = scoreForTrow(startRange, endRange); // [0; 10]

        for (int trowIndex = 0; trowIndex < 2; trowIndex++) {   

            // write strike
            if (scoreCount == 10) {
                resData[frameIndex][trowIndex] = 10;
                resData[frameIndex][trowIndex + 1] = 0;
                break;
            }

            // write other results
            else if (trowIndex == 1) { // second trow
                
                resData[frameIndex][trowIndex] = scoreForTrow(startRange, endRange - scoreCount); // [0; 10 - first trow]
            }
            else { // first trow
                resData[frameIndex][trowIndex] = scoreCount;
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