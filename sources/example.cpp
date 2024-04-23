#include <iostream>
#include "example.h"

/* 
 * calculate count score of downed pins
 * return any number from range [startRange; endRange]
 */ 
int scoreForTrow(int startRange, int endRange) {
    srand(time(NULL)); // Initializing pseudorandom number generator
    int x = rand() % (endRange - startRange + 1) + startRange; 
    return x;
}

