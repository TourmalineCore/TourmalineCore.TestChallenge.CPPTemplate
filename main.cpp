#include <iostream>
#include "includes/example.h"


int main(int argc, char* argv[]) {
    
    srand(time(NULL)); // Initializing pseudorandom number generator

    paint(scoreVector());
    
    return 0;
}