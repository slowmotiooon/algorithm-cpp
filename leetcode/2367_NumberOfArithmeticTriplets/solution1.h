#pragma once

#include <vector>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
	int n = nums.size();
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (nums[j] > nums[i] + diff) break;
			if (nums[j] < nums[i] + diff) continue;
			for (int k = j + 1; k < n; k++) {
				if (nums[k] > nums[j] + diff) break;
				if (nums[k] < nums[j] + diff) continue;
				else ans++;
			}
		}
	}
	return ans;
}

// 通过 | 0ms | 10.69MB
// O(n^3) | O(1)
// 暴力算法