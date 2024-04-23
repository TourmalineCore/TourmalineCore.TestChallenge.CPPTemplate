#include <iostream>
#include "includes/example.h"


int main(int argc, char* argv[]) {

    srand(time(NULL)); // Initializing pseudorandom number generator

    vector<vector<int>> vect = scoreVector();
    vector<int> data = sumResultInFrame(vect);

    paint(vect);
    paint(data);
    
    return 0;
}