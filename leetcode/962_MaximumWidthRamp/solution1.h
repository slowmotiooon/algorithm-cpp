#pragma once

#include <vector>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
	int ans = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums.size() - 1 - i < ans) break;
		for (int j = nums.size() - 1; j > i; j--) {
			if (nums[i] <= nums[j]) {
				if (ans < j - i) ans = j - i;
				break;
			}
		}
	}
	return ans;
}

// 通过 | 2368ms | 30.91MB\
// O(n^2) | O(1)
// 暴力O(n^2)算法