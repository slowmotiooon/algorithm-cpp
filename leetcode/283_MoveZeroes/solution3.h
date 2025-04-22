#pragma once

#include <vector>
using namespace std;

void swap(int& n1, int& n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void moveZeroes(vector<int>& nums) {
	if (nums.size() < 2) return;

	int zero = 0, nonzero = 0;

	while (1) {
		if (nonzero >= nums.size() || zero >= nums.size()) break;

		while (zero<nums.size() && nums[zero] != 0) zero++;
		while (nonzero<nums.size() && nums[nonzero] == 0) nonzero++;

		if (nonzero >= nums.size() || zero >= nums.size()) break;

		if (nonzero > zero) {
			swap(nums[zero], nums[nonzero]);
			zero++;
		}

		nonzero++;
	}
}

// 运行结果：
// 通过 | 13ms | 21.35MB
// 使用了双指针，快指针找非零项，慢指针找0，然后发现顺序不对时调换顺序，再开始下一次循环。