#include<iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int m, k;
	cin >> m >> k;
	cout << maxSum(nums, m, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/description/		1546
// tag: #slidingwindow