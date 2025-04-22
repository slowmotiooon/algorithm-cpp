#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> start(n);
	for (int& i : start) cin >> i;

	int d;
	cin >> d;

	cout << maxPossibleScore(start, d) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximize-score-of-numbers-in-ranges/description/