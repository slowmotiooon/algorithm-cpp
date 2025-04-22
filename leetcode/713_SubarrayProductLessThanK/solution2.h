#pragma once

#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int n = nums.size();
	int product = 1;
	if (k == 0) return 0;
	int left = 0;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		product *= nums[i];
		while (product >= k) {
			product /= nums[left];
			left++;
		}
		ans += i - left + 1;
	}
	return ans;
}

// Í¨¹ý | 67ms | 62.55MB
// O(n) | O(1)