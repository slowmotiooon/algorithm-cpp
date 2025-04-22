#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
	int left = 1, right = *max_element(nums.begin(), nums.end());
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int sum = 0;
		for (int x : nums) {
			sum += x / mid + (x % mid != 0);
		}
		if (sum <= threshold) right = mid - 1;
		else left = mid + 1;
	}
	return right + 1;
}

// 通过 | 27ms | 24.42MB
// O(n*logM) M为nums中的最大值 | O(1)
