#pragma once

#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int max = -2147483648, min = 2147483647;
	int sum = 0;

	for (int i : nums) {
		sum += i;
		if (sum > max) max = sum;
		if (sum < min) min = sum;
	}

	return max - min;
}

// 运行结果： 解答错误
// O(n) | O(1)
// 没有考虑到如果max前缀和所在位置在min前缀和位置左边的话，max-min将是最小字串的值。