#pragma once

#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	vector<int> sums = { 0 };
	int sum = 0;
	int end = 0;
	int result = 0;

	for (int i : nums) {
		sum += i;
		sums.push_back(sum);
	}

	for (int i = 0; i != sums.size()-1; i++) {
		for (int j = i + 1; j != sums.size(); j++) {
			if (sums[j] - sums[i] == k) result++;
		}
	}

	return result;
}

// 运行结果：
// 通过 | 2877ms | 35.37MB
// O(n^2) | O(n)
// 用到了前缀和，但是也很常规，没有优化算法。前缀和省略了solution2中每次都要求和的时间损耗。