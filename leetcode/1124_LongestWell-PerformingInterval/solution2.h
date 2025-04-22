#pragma once

#include <vector>
using namespace std;

int longestWPI(vector<int>& hours) {
	int max = 0;
	for (int i = 1; i <= hours.size(); i++) {
		int start = 0, end = 0;
		int sum = 0;
		bool checked = false;
		for (; end < hours.size(); end++) {
			sum += hours[end] > 8 ? 1 : -1;
			if (end < i - 1) continue;
			if (sum > 0) {
				checked = true;
				break;
			}
			sum += hours[start++] <= 8 ? 1 : -1;
		}
		if (checked) max = max < i ? i : max;
	}
	return max;
}

// 通过 | 2431ms | 23.85MB
// O(n^2) | O(1)
// 暴力做法，虽然二分不能用，但是暴力还是能用的