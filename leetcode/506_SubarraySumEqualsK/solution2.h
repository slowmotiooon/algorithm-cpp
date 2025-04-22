#pragma once

#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int result = 0;

	for (int i = 0; i < nums.size(); i++) {
		int sum = 0;
		int j = i;
		for (; j < nums.size(); j++) {
			sum += nums[j];
			if (sum == k) result++;
		}
	}

	return result;
}

// 运行结果：超出时间限制
// 应该就差点，使用的是暴力算法，时间复杂度O(n^2)，慢是必然的。
// 起初这一版本有剪枝，比如在当前i下最长的字串和小于k时就结束循环，但是这是假定nums中均为正数的。