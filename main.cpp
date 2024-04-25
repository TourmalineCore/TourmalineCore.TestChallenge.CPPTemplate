#include <iostream>
#include "includes/bowlingGame.h"


int main(int argc, char* argv[]) {

    /* 
     * first version wich create random event knocking out pins
     * random strike, spare, unlucky throws etc
     */
    
    srand(time(NULL)); // Initializing pseudorandom number generator

    vector<vector<int>> vect = scoreVector(); // create vect with random scores
    vector<int> data = sumResultInFrame(vect); // sum scores by frame
    int res =  totalScore(data); // calc total scores

    paint(vect);
    paint(data);
    paint(res);

    /* 
     * second version when u write your result in matrix
     * write strike, tripple strike, usual throws and spare
     */

    // our vector with downed pins by frame
    vector <vector <int>> resData{
    {10, 0}, {7, 3}, {7, 2}, {9, 1}, {10, 0},
    {10, 0}, {10, 0}, {2, 3}, {6, 4}, {7, 3, 3} };

    vector<int> scoresByFrames = sumResultInFrame(resData); // sum scores by frame
    int totalScores =  totalScore(scoresByFrames); // calc total scores

    paint(resData);
    paint(scoresByFrames);
    paint(totalScores);

    // paint throw result in frame (start index 1)
    paint(resData, 1, 4); // 4 frame 1st throw

    // paint frame result (start index 1)
    paint(scoresByFrames, 1); // 1 frame

    return 0;
    
}