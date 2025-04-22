#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

long long maxSum(vector<int>& nums, int m, int k) {
	int n = nums.size();
	long long sum = 0;
	long long max = 0;
	unordered_map<int,int> hash;
	for (int i = 0; i < n; i++) {
		hash[nums[i]]++;
		sum += nums[i];
		if (i < k - 1) continue;
		if (hash.size() >= m) max = max > sum ? max : sum;
		sum -= nums[i - k + 1];
		hash[nums[i - k + 1]] == 1 ? hash.erase(nums[i - k + 1]) : hash[nums[i - k + 1]]--;
	}
	return max;
}

// 通过 | 134ms | 68.55MB
// O(n) | O(k) k为窗口长度
//