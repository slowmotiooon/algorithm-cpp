#pragma once

#include <vector>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
	int max = 0;
	for (int i : nums) {
		if (i > max) max = i;
	}

	int count = 0;
	int n = nums.size();
	int left = 0;
	int right = 0;
	long long result = 0;
	while (1) {
		while (count != k && right < n) {
			if (nums[right] == max) count++;
			right++;
		}
		if (right == n && count != k) return result;
		int m = n - right + 1;
		result += m;
		while (count==k && left < n) {
			if (nums[left] == max) count--;
			else result += m;
			left++;
		}
	}
	return result;
}

// 运行结果：
// 通过 | 192ms | 117.72MB
// O(n) | O(1)
// 方法：滑动窗口。一定有什么东西在拖慢速度。
// 思路为：		示例	1	3	2	3	3,	k = 2
// 第一次循环：		1	3	2	3
//					+m				+1	+0		m = 1 +1 +0 = 2,	result += m +m (result = 0 + 4 = 4)
// 第二次循环：				2	3	3
//							+m			+0		m = 1 +0 = 1,		result += m +m (result = 4 + 2 = 6)
// 答案为6