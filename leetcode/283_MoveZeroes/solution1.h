#pragma once

#include <vector>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
	vector<int> result;
	int zeros = 0;

	for (int i : nums) {
		if (i == 0)zeros++;
		else result.push_back(i);
	}

	for (int i = 0; i < zeros; i++) {
		result.push_back(0);
	}
	nums = result;
}

// 运行结果：
// 通过 | 18ms | 22.67MB
// 由于开辟了新的result盛放改变后的结果，导致空间使用较多。