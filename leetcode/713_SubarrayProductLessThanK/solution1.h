#pragma once

#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int product = 1;
	int ans = 0;
	int right = 0;
	for (int i = 0; i < nums.size(); i++) {
		right = i;
		while (right < nums.size()) {
			product *= nums[right];
			if (product >= k) break;
			ans++;
			right++;
		}
		product =1;
	}
	return ans;
}

// Í¨¹ý | 1800ms | 62.63MB
// O(n^2) | O(1)
// Ã¶¾Ù+¼ôÖ¦
