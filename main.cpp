#include <iostream>
#include "includes/bowlingGame.h"


int main(int argc, char* argv[]) {

    // create our vector with downed pins by frame
    vector <vector <int>> resData {
    {10, 0}, {7, 3}, {7, 2}, {9, 1}, {10, 0},
    {10, 0}, {10, 0}, {2, 3}, {6, 4}, {7, 3, 3} };

    vector <vector <int>> resData2 {
    {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
    {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0} };

    BowlingGame firstGame;
    firstGame.setResult(resData2);
    firstGame.sumResultInFrame();
    firstGame.calcTotalScore();
    firstGame.paintAllThrows();
    firstGame.paintTotalScore();
    firstGame.paintResultByFrame();

    int x = firstGame.getResultByFrame(1);
    cout << "\nResult by first frame = " << x << "\n";

    int y = firstGame.getResultByThrow(4, 1);
    cout << "\nResult in 4th frame by first throw = " << y << "\n";
    
}