#pragma once

#include <vector>
#include <cmath>
using namespace std;

int maxArea(vector<int>& height) {
	int start = 0, end = height.size() - 1;
	int max = 0;

	while (start < end) {
		int area = min(height[start], height[end]) * (end - start);
		if (area > max) max = area;
		if (height[start] > height[end]) end--;
		else start++;
	}

	return max;
}

// 运行结果：
// 通过 | 84ms | 60.27MB
// 依据官方题解思路（双指针+贪心）写的代码，大幅减少了时间复杂度（O(n)）。