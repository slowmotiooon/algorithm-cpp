#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<vector<int>> points;
	for (int i = 0; i < total; i++) {
		vector<int> line(2);
		cin >> line[0] >> line[1];
		points.push_back(line);
	}

	int w;
	cin >> w;

	cout << minRectanglesToCoverPoints(points, w);

	return 0;
}

// https://leetcode.cn/problems/minimum-rectangles-to-cover-points/		ÄÑ¶È·Ö£º1401