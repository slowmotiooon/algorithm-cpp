#pragma once

#include <vector>
#include <algorithm>
using namespace std;

long long countFairPairs(vector<int>& nums, int lower, int upper) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	long long ans = 0;
	int left = 0; int right = n - 1;
	while (left < right) {
		while (right > left && nums[left] + nums[right] > upper) right--;
		ans += right - left;
		left++;
	}
	left = 0;
	right = n - 1;
	while (left < right) {
		while (right > left && nums[left] + nums[right] >= lower) right--;
		ans -= right - left;
		left++;
	}
	return ans;
}

// 通过 | 120ms | 58.85MB
// O(nlogn) | O(1)
// 三指针，两次遍历，为了保险没写一次遍历的。