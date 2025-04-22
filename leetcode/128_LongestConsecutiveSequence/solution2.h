#pragma once

#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_set<int> numSet;
	for (int item : nums) {
		numSet.insert(item);
	}

	int max = 0;
	int current = 0;
	for (int item : nums) {
		if (numSet.find(item - 1) != numSet.end()) continue;
		else {
			for (int i = item; numSet.find(i) != numSet.end(); i++) {
				current++;
			}
			if (current > max) max = current;
			current = 0;
		}
	}
	return max;
}

// 运行结果：
// 通过 | 1118ms | 72.88MB
// 按照题解思路来的，不知道怎么回事，用时很长。