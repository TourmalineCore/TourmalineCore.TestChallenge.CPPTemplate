#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>

using namespace std;

int scoreForThrow(int startRange, int endRange);

vector<vector<int>> scoreVector();
void paint(vector<vector<int>> scoreVector);

vector<int> sumResultInFrame(vector<vector<int>> scoreVector);
void paint(vector<int> sumResultInFrame);

int totalScore(vector<int> frameResData);
void paint(int totalScore);

void paint(vector<vector<int>> scoreVector, int frameIndex, int throwIndex);
void paint(vector<int> sumResultInFrame, int frameIndex);