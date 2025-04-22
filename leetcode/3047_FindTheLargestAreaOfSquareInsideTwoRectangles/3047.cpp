#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<vector<int>> bottomLeft, topRight;
	for (int i = 0; i < total; i++) {
		vector<int> line(2);
		cin >> line[0] >> line[1];
		bottomLeft.push_back(line);
	}
	for (int i = 0; i < total; i++) {
		vector<int> line(2);
		cin >> line[0] >> line[1];
		topRight.push_back(line);
	}

	cout << largestSquareArea(bottomLeft, topRight) << endl;
	return 0;
}

// https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles/description/		ÄÑ¶È·Ö£º1602
// tag: #geometry #math #enum
