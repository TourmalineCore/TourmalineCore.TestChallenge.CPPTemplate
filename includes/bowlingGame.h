#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>

using namespace std;

int scoreForThrow(int startRange, int endRange);

vector<vector<int>> scoreVector();
vector<vector<int>> scoreVector2(int data[10][2]);
void paint(vector<vector<int>> scoreVector);

vector<int> sumResultInFrame(vector<vector<int>> scoreVector);
void paint(vector<int> sumResultInFrame);

int totalScore(vector<int> frameResData);
void paint(int totalScore);