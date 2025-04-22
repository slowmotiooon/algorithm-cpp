#pragma once

#include <vector>
using namespace std;

int longestWPI(vector<int>& hours) {
	int left = 1, right = hours.size();
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int start = 0, end = 0;
		int sum = 0;
		bool checked = false;
		for (; end < hours.size(); end++) {
			sum += hours[end] > 8 ? 1 : -1;
			if (end < mid - 1) continue;
			if (sum > 0) {
				checked = true;
				break;
			}
			sum += hours[start++] <= 8 ? 1 : -1;
		}
		if (!checked) right = mid - 1;
		else left = mid + 1;
	}
	return right; 
}

// 二分+定长滑窗？
// 解答错误。示例 [9 6 9] 不通过
// 这里不满足二分的条件，没有一个临界点，使得之前的值全部不符合条件，之后的点全部符合条件。