#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int max = 1;
	int current = 1;

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	for(int i = 1;i<nums.size();i++)
	{
		if (nums[i] == nums[i - 1] + 1) current++;
		else {
			if (current > max) max = current;
			current = 1;
		}
	}

	if (current > max) max = current;

	return max;
}

// 运行结果：
// 通过 | 75ms | 48.65MB
// 先将nums排序，再去重，即可通过一次遍历获得最长的连续序列。