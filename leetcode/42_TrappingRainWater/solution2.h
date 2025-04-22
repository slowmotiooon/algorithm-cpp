#pragma once

#include <vector>
using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	int maxIndex = max_element(height.begin(), height.end()) - height.begin();
	int end = 0;
	int ans = 0;
	for (int i = 0; i < maxIndex && maxIndex != 0; i++) {
		if (height[i] > height[end]) end = i;
		else ans += height[end] - height[i];
	}
	end = n - 1;
	for (int i = n - 1; i > maxIndex && maxIndex != n - 1; i--) {
		if (height[i] > height[end]) end = i;
		else ans += height[end] - height[i];
	}
	return ans;
}

// 通过 | 24ms | 24.28MB
// O(n) | O(1)
// 双指针，找到最大值后从前后两侧遍历。