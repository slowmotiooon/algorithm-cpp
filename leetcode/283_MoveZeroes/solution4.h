#pragma once

#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int offset = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) offset++;
		if (nums[i] != 0 && offset != 0) {
			nums[i - offset] = nums[i];
			nums[i] = 0;
		}
	}
}

// 运行结果：
// 通过 | 21ms | 21.39MB
// 题解 https://leetcode.cn/problems/move-zeroes/solutions/2821184/san-chong-jie-fa-duo-yu-yan-you-pei-tu-b-1d3s/?envType=study-plan-v2&envId=top-100-liked 中的方法一