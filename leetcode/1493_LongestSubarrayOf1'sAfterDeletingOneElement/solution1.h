#pragma once

#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
	int start = -1;
	int nextZero = -1;
	int end = 0;
	int max = 0;
	for (; end < nums.size(); end++) {
		if (!nums[end]) {
			if (nextZero == -1) nextZero = end;
			else break;
		}
	}
	if (end == nums.size()) return nums.size() - 1;

	while (end <= nums.size()) {
		if (end - start - 2 > max) max = end - start - 2;
		start = nextZero;
		nextZero = end;
		end++;
		while (end < nums.size() && nums[end]) end++;
	}
	return max;
}

// Í¨¹ý | 41ms | 57.64MB
// O(n) | O(1)