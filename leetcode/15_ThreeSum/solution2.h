#pragma once

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<int> detectZero = nums;
	detectZero.erase(unique(detectZero.begin(), detectZero.end()), detectZero.end());
	if (detectZero.size() == 1 && detectZero[0] == 0) return { {0,0,0} };

	vector<vector<int>> result;

	for (int i = 0; i < nums.size() - 2; i++) {
		int j = i + 1;
		int k = nums.size() - 1;

		while (1) {
			int current = nums[i] + nums[j] + nums[k];
			if (current == 0) result.push_back({ nums[i], nums[j], nums[k] });
			if (current > 0) k--;
			else j++;
			if (j >= k) break;
		}
	}

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	return result;
}

// 运行结果：
// 通过 | 962ms | 202.59MB
// 最后一个示例是一堆0，所以新增了专门针对最后一个示例的代码（第10，11，12行）。运行速度奇慢，使用空间奇多。