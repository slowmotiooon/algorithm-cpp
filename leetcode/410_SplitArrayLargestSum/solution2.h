#pragma once

#include <vector>
#include <numeric>
using namespace std;

int splitArray(vector<int>& nums, int k) {
	int right = accumulate(nums.begin(), nums.end(), 0);
	int left = max(right / k,*max_element(nums.begin(),nums.end()));

	while (left <= right) {
		int mid = left + (right - left) / 2;
		int sum = 0;
		int count = 0;
		for (int x : nums) {
			if (sum + x > mid) {
				sum = x;
				count++;
			}
			else sum += x;
		}
		if (count + 1 <= k) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// 通过 | 3ms | 9.20MB
// O(n*log(m)) m为nums总和与(总和的1/k与nums中最大元素的最大值)之差 | O(1)
// 思路来源：https://leetcode.cn/problems/split-array-largest-sum/solutions/2613046/er-fen-da-an-fu-ti-dan-pythonjavacgojsru-n5la
