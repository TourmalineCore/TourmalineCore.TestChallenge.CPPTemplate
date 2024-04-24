#include "helpForTest.h"

// help func, count in one trow must be [0; 10]
bool checkSize(int count) {
    if (count < 0 || count > 10) return false;
    return true;
}