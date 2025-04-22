#pragma once

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	
	sort(nums.begin(), nums.end());

	int p1, p2;
	int p3 = nums.size() - 1;

	for (p1 = 0; p1 < nums.size() - 2; p1++) {
		for (p2 = p1 + 1; p2 < nums.size()-1; ) {
			if (nums[p1] + nums[p2] + nums[p3] == 0) result.push_back({ nums[p1],nums[p2],nums[p3] });
			if (nums[p1] + nums[p2] + nums[p3] < 0) {
				p3 = nums.size() - 1;
				p2++;
				continue;
			}
			p3--;
			if (p3 <= p2) {
				p3 = nums.size() - 1;
				p2++;
			}
		}
	}

	sort(result.begin(), result.end());

	result.erase(unique(result.begin(), result.end()), result.end());

	return result;
}

// 运行结果：
// 超出时间限制
// 暴力算法加部分剪枝，最差O(n^3)