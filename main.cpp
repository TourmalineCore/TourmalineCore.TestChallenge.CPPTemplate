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

    // our matrix with downed pins by frame
    int scoresInMatrix[10][2] { 
    {1, 2}, {4, 5}, {10, 0}, {5, 5}, {9, 1}, 
    {5, 5}, {5, 5}, {4, 7}, {4, 5}, {4, 5} };

    vector<std::vector<int>> scoresInVector = scoreVector2(scoresInMatrix); // convert matrix to vector
    vector<int> scoresByFrames = sumResultInFrame(scoresInVector); // sum scores by frame
    int totalScores =  totalScore(scoresByFrames); // calc total scores

    paint(scoresInVector);
    paint(scoresByFrames);
    paint(totalScores);

    return 0;
    
}