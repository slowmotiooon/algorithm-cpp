#pragma once

#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
	if (!nums.size()) return;
	int passed = 0;
	for (auto it = nums.begin(); passed<nums.size();passed++) {
		if (*it == 0) {
			it = nums.erase(it);
			nums.push_back(0);
		}
		else it++;
	}
}

// 运行结果：
// 通过 | 24ms | 21.45MB
// 当0较多的时候，大量的删除和添加操作会使用很多时间。