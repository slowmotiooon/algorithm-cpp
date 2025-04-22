#pragma once

#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				return { i,j };
			}
		}
	}
	return {};
}

// 运行结果：
// 通过 | 61ms | 12.63MB

//所用方法：两层for循环穷举，用时较长