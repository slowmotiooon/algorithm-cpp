#pragma once

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> result;

	for (int i = 0; i < nums.size() - 2; i++) {

		if (i && nums[i - 1] == nums[i]) continue;	//跳过重复数字
		if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;	//剪枝，如果在nums[i]基础上三个最小的数加起来大于0的话，说明之后的所有组合的和都大于0
		if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) continue;	//剪枝，如果nums[i]和最大的两个数的和小于0，则需要更大的i

		int j = i + 1;
		int k = nums.size() - 1;

		while (1) {
			int current = nums[i] + nums[j] + nums[k];
			if (current == 0) result.push_back({ nums[i], nums[j], nums[k] });
			if (current > 0) {
				k--;
				while (k > 0 && nums[k] == nums[k + 1]) k--;	//跳过重复数字
			}
			else {
				j++;
				while (j < nums.size() - 1 && nums[j] == nums[j - 1]) j++;	//跳过重复数字
			}
			if (j >= k) break;
		}
	}

	return result;
}

// 运行结果：
// 通过 | 74ms | 26.82MB
// 在算法2的基础上优化，把去重代码放在主循环内部，再通过剪枝优化，大幅提升了运行速度和使用空间。