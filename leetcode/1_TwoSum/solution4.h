#pragma once

#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
	unordered_map<int, int> hashMap;

	for (int i = 0; i < nums.size(); i++) {
		if (hashMap.find(nums[i]) != hashMap.end() && nums[i] * 2 == target) return { hashMap[nums[i]],i };
		else hashMap[nums[i]] = i;

		if (hashMap.find(nums[i]) != hashMap.end() 
			&& hashMap.find(target - nums[i]) != hashMap.end() && 
			nums[i]*2!=target) 
			return {min(hashMap[nums[i]], hashMap[target - nums[i]]),max(hashMap[nums[i]], hashMap[target - nums[i]])};
	}

	return {};
}

// 运行结果：
// 通过 | 7ms | 14.22MB
// 改进了solution3中的哈希列表。使哈希列表在不需要用到vector盛放nums索引的同时避免了重复的数字。时间和空间上都有进步。