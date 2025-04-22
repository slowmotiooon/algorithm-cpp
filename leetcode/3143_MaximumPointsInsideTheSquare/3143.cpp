#include <iostream>
#include "solution3.h"
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<vector<int>> points(s.size());
	for (vector<int>& x : points) {
		int i, j;
		cin >> i >> j;
		x = { i,j };
	}

	cout << maxPointsInsideSquare(points, s) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximum-points-inside-the-square/description/		1697