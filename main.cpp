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

    return 0;
}