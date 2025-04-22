#pragma once

#include <vector>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
	int sum = 0;
	int ans = 0;
	int left = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		while (sum > goal && left<=i) {
			sum -= nums[left];
			left++;
		}
		ans += i - left + 1;
	}
	sum = 0;
	left = 0;
	if (goal==0) return ans;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		while (sum >= goal && left <= i) {
			sum -= nums[left];
			left++;
		}
		ans -= i - left + 1;
	}
	return ans;
}

// Í¨¹ý | 25ms | 30.79MB
// O(n) | O(1)