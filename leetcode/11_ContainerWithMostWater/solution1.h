#pragma once

#include <vector>
#include <cmath>
using namespace std;

int maxArea(vector<int> height) {
	int max = 0;
	for (int i = 0; i < height.size() - 1; i++) {
		for (int j = i + 1; j < height.size(); j++) {
			int area = (j - i) * min(height[i], height[j]);
			if (area > max) max = area;
		}
	}
	return max;
}

// 运行结果：
// 超出时间限制。
// 最暴力的方法，用时也最长。