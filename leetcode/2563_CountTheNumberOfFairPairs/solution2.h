#pragma once

#include <vector>
#include <algorithm>
using namespace std;

long long countFairPairs(vector<int>& nums, int lower, int upper) {
	int n = nums.size();
	long long ans = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 1 && 2 * nums[i] <= upper; i++) {
		int left = i + 1, right1 = n;
		while (left < right1) {
			int mid = left + (right1 - left) / 2;
			if (nums[mid] + nums[i] >= lower) right1 = mid;
			else left = mid + 1;
		}
		left = i + 1;
		int right2 = n;
		while (left < right2) {
			int mid = left + (right1 - left) / 2;
			if (nums[mid] + nums[i] > upper) right2 = mid;
			else left = mid + 1;
		}
		ans += right2 - right1;
	}
	return ans;
}

// Í¨¹ý | 153ms | 58.96MB
// O(n*logn) | O(1)