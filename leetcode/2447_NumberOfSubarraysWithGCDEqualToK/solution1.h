#pragma once

#include <vector>
using namespace std;

constexpr int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int subarrayGCD(vector<int>& nums, int k) {
	int right = 0;
	int left = 0;
	int n = nums.size();
	int result = 0;
	
	while (1) {
		if (nums[right] % k == 0) {
			left = right;
			while (right < n && nums[right] % k == 0) {
				if (nums[right] == k) result++;
				right++;
			}
		}
		while (left < right) {
			int gcdNum = nums[left];
			for (int i = left + 1; i < right; i++) {
				gcdNum = gcd(gcdNum, nums[i]);
				if (gcdNum == k) result++;
			}
			left++;
		}
		while (right < n && nums[right] % k != 0) right++;
		if (left == n || right == n) break;
	}
	return result;
}

// 通过 | 4ms | 11.35MB
// O(n) 忽略gcd用时,最坏O(n^2) | O(1)