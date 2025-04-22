#pragma once

#include <vector>
using namespace std;

long long getArea(long long& current, int new1) {
	if (current < new1) return current * current;
	else return new1 * new1;
}

long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
	long long ans = 0;
	for (int i = 0; i < bottomLeft.size() - 1; i++) {
		for (int j = i + 1; j < bottomLeft.size(); j++) {
			long long current;
			if (bottomLeft[j][0] >= topRight[i][0]) continue;
			else if (bottomLeft[j][0] >= bottomLeft[i][0]) {
				if (topRight[j][0] >= topRight[i][0]) current = topRight[i][0] - bottomLeft[j][0];
				else current = topRight[j][0] - bottomLeft[j][0];
				if (bottomLeft[j][1] >= topRight[i][1]) continue;
				else if (bottomLeft[j][1] >= bottomLeft[i][1]) {
					if (topRight[j][1] >= topRight[i][1]) current = getArea(current, topRight[i][1] - bottomLeft[j][0]);
					else current = getArea(current, topRight[j][1] - bottomLeft[j][1]);
				}
			}
			else {
				if (topRight[j][0] <= bottomLeft[i][0]) continue;
				else if (topRight[j][0] <= topRight[i][0]) {
					current = topRight[j][0] - bottomLeft[i][0];
					if (topRight[j][1] <= bottomLeft[i][1]) continue;
					else if (topRight[j][1] <= topRight[i][1]) current = getArea(current, topRight[j][1] - bottomLeft[i][1]);
					else current = getArea(current, topRight[i][1] - bottomLeft[i][1]);
				}
				else {
					current = topRight[i][0] - bottomLeft[i][0];
					if (topRight[j][1] <= bottomLeft[i][1]) continue;
					else if (topRight[j][1] <= topRight[i][1]) current = getArea(current, topRight[j][1] - bottomLeft[i][1]);
					else current = getArea(current, topRight[i][1] - bottomLeft[i][1]);
				}
			}
			if (current > ans) ans = current;
		}
	}
	return ans;
}

// 解答错误
// O(n^2) | O(1)
// 条件判断太复杂了