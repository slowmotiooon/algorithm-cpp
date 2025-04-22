#pragma once

#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
	if (k > nums.size()) k = k % nums.size();

	for (; k != nums.size(); k++) {
		nums.push_back(nums[0]);
		nums.erase(nums.begin());
	}
}

// 运行结果：超出时间限制
// 合理猜测时间复杂度应该是O(kn)