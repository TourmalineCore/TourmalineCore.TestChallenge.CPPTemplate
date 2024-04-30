#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <numeric>

using namespace std;

class BowlingGame {

private: vector<vector<int>> scoreVector;
		 vector<int> frameResData;
		 int totalScore;

public: void setResult(vector<vector<int>> vec);
		void sumResultInFrame();
		void calcTotalScore();
		void paintAllThrows();
		void paintResultByFrame();
		void paintTotalScore();
		int getResultByFrame(int frameIndex);
		int getResultByThrow(int frameIndex, int throwIndex);
        int getTotalScore();
        vector<vector<int>> getScoreVector();
        vector<int> getFrameResData();

};