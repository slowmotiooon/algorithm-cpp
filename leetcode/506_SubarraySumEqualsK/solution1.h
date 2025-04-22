#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int start = 0, end = 0;
	int sum = 0;
	bool endChanged = true;

	int result = 0;

	while (end < nums.size() && start <= end) {
		if(endChanged) sum += nums[end];

		if (sum == k) {
			result++;
			end++;
			endChanged = true;
		}
		else if (sum < k) {
			end++;
			endChanged = true;
		}
		else {
			sum -= nums[start];
			start++;
			endChanged = false;
		}
	}
	return result;
}

// 运行结果：解答错误
// 问题在与要想用这一算法（滑动窗口），必须要经过排序，但是排序后的索引与原索引不同。