#pragma once

#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int sum = 0;
	int minSum = 0;
	int result = -2147483648;

	for (int i : nums) {
		sum += i;
		if (sum - minSum > result) result = sum - minSum;
		if (sum < minSum) minSum = sum;
	}

	return result;
}

// 运行结果：
// 通过 | 87ms | 69.01MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/maximum-subarray/solutions/2533977/qian-zhui-he-zuo-fa-ben-zhi-shi-mai-mai-abu71 的方法一
// 使用了前缀和。
// 最大字串，就需要前缀和数组中的最大值减去前缀和数组中的最小值，且最大值的对应索引要大于最小值对应索引。
// 因此，可以采用在遍历时更新最小前缀和，与此同时计算当前前缀和与最小前缀和的差值，再更新此差值的最大值。
// 相关题目： 121. 买卖股票的最佳时机

// 补充：还有一种更耗时的方法，即比较所有前缀和之差，当然时间复杂度来到了O(n^2), 空间复杂度也有O(n)