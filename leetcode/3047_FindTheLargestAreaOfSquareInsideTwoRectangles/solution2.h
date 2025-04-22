#pragma once

#include <vector>
#include <cmath>
using namespace std;

long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
	long long ans = 0;
	for (int i = 0; i < bottomLeft.size() - 1; i++) {
		for (int j = i + 1; j < bottomLeft.size(); j++) {
			int left = max(bottomLeft[i][0], bottomLeft[j][0]);
			int right = min(topRight[i][0], topRight[j][0]);
			int top = min(topRight[i][1], topRight[j][1]);
			int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
			if (right - left < 0 || top - bottom < 0) continue;
			long long a = min(right - left, top - bottom);
			long long area = a * a;
			if (ans < area) ans = area;
		}
	}
	return ans;
}

// 通过 | 234ms | 57.97MB
// O(n^2) | O(1)
// 思路来自：https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles/solutions/2653554/jian-ji-xie-fa-wu-xu-fen-lei-tao-lun-pyt-b7yq
// 直接简化了一堆if