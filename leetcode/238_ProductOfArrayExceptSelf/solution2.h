#pragma once

#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size() == 2) return { nums[1],nums[0] };
	int n = nums.size();
	vector<int> result(n,1);

	for (int i = n - 1; i > 0; i--) {
		if (i == n - 1) result[i - 1] = nums[n - 1];
		else result[i - 1] = nums[i] * result[i];
	}

	int init = 1;
	for (int i = 1; i < n; i++) {
		init *= nums[i - 1];
		result[i] *= init;
	}

	return result;
}

// 运行结果：
// 通过 | 28ms | 37.56MB
// O(n) | O(1)（忽略返回值）
// 思路来自：https://leetcode.cn/problems/product-of-array-except-self/solutions/2783788/qian-hou-zhui-fen-jie-fu-ti-dan-pythonja-86r1/