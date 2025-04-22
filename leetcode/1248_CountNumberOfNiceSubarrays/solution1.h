#pragma once

#include <vector>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
	int n = nums.size();
	int count = 0;
	int left = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] & 1) count++;
		while (count > k && left <= i) {
			if (nums[left] & 1) count--;
			left++;
		}
		ans += i - left + 1;
	}
	if (k == 0) return ans;
	left = 0;
	count = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] & 1) count++;
		while (count >= k && left <= i) {
			if (nums[left] & 1) count--;
			left++;
		}
		ans -= i - left + 1;
	}
	return ans;
}

// Í¨¹ý | 109ms | 68.62MB
// O(n) | O(1)
