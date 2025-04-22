#pragma once

#include <vector>
#include <algorithm>
using namespace std;

long long min(vector<long long> nums) {
	long long minVal = LLONG_MAX;
	for (auto i : nums) {
		if (i < minVal) minVal = i;
	}
	return minVal;
}

long long max(vector<long long> nums) {
	long long maxVal = LLONG_MIN;
	for (auto i : nums) {
		if (i > maxVal) maxVal = i;
	}
	return maxVal;
}

long long maxStrength(vector<int>& nums) {
	long long minVal = nums[0], maxVal = nums[0];
	for (int i = 1; i < nums.size();i++) {
		long long tmp = minVal;
		minVal = min({ minVal,minVal * nums[i],maxVal * nums[i],nums[i]});
		maxVal = max({ maxVal,tmp * nums[i],maxVal * nums[i],nums[i] });
	}
	return maxVal;
}

// 通过
// leetcode不用重载max和min函数，不知道它的函数哪来的。