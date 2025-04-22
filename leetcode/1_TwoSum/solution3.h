#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
	unordered_map<int, vector<int>> hashMap;
	for (int i = 0; i < nums.size(); i++) {
		hashMap[nums[i]].push_back(i);
	}

	if (target % 2 == 0 && hashMap[target / 2].size() == 2) return hashMap[target / 2];

	for (int i : nums) {
		if (target % 2 == 0 && hashMap[target / 2].size() == 1 && i == target / 2) continue;
		if (!hashMap[i].empty() && !hashMap[target - i].empty()) return { hashMap[i][0], hashMap[target - i][0] };
	}
	return {};
}

// 运行结果：
// 通过 | 33ms | 18.86MB

// 所用方法：使用哈希表重新构造数组，键值为nums中的数字，映射值为其所在索引的数组。
// 该方法解决了solution2中无序数组的问题，同时将时间复杂度减小到O(n)，但是由于每个哈希表的元素都要开辟一个新的vector数组，导致空间使用较多。