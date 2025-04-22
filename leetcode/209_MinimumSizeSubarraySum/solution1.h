#pragma once

#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
	int n = nums.size();
	int left = 0, right = 0;
	int cur = 0;
	int min = INT_MAX;
	while (right < n) {
		while (right < n && cur < target) {
			cur += nums[right];
			right++;
		}
		if (right == n && cur < target && left == 0) return 0;
		while (left < right && cur >= target) {
			if (min > right - left) min = right - left;
			cur -= nums[left];
			left++;
		}
	}
	return min;
}

// Í¨¹ý | 32ms | 30.18MB
// O(n) | O(1)