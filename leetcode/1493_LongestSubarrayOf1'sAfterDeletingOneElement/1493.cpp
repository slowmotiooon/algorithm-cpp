#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) {
		cin >> i;
	}

	cout << longestSubarray(nums) << endl;
	return 0;
	
}

// https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/description/		1423