#pragma once

#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
	if (k > nums.size()) k = k % nums.size();
	if (k == nums.size()) return;
	nums.push_back(nums[0]);
	nums.erase(nums.begin());
	rotate(nums, k + 1);
}

//运行结果：超出时间限制
//使用递归，并且把顺向旋转k次变成了逆向旋转size-k次。