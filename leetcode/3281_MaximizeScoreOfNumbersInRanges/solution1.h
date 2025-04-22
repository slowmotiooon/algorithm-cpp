#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int maxPossibleScore(vector<int>& start, int d) {
	sort(start.begin(), start.end());
	int left = 0;
	int right = (start.back() + d - start[0]) / (start.size() - 1);

	while (left <= right) {
		int mid = left + (right - left) / 2;
		int s = start[0];
		bool checked = true;
		for (int i = 1; i < start.size(); i++) {
			s = max(s + mid, start[i]);
			if (s > start[i] + d) {
				checked = false;
				break;
			}
		}
		if (!checked) right = mid - 1;
		else left = mid + 1;
	}
	return right;
}

// 通过 | 232ms | 107.06MB
// 复杂度见题解
// 思路来自：https://leetcode.cn/problems/maximize-score-of-numbers-in-ranges/solutions/2908931/er-fen-da-an-zui-da-hua-zui-xiao-zhi-pyt-twe2