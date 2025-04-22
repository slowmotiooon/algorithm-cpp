#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> hashList;
	for (int i = 0; i < nums.size(); i++) {
		if (hashList[nums[i]] == 0 && i != 0 && nums[0] != i) {
			if (2 * nums[i] == target && nums[i-1] == nums[i]) return {0,i};
		}
		else if (hashList[nums[i]] != 0 && 2 * nums[i] == target) return { hashList[nums[i]], i };

		hashList[nums[i]] = i;
	}

	for (int i = 1; i <= target / 2; i++) {
		if (hashList[i] == 0 && hashList[target - i] == 0) continue;
		if (hashList[i] == 0) {
			if (i == nums[0]) return { hashList[i], hashList[target - i] };
		}
		if (hashList[target - i] == 0) {
			if (target - i == nums[0])return { hashList[i],hashList[target - i] };
		}

		return { hashList[i],hashList[target - i] };
	}
	return {};
}

// 运行结果：失败
// 原因：未处理无序的nums数组。