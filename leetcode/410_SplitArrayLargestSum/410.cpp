#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	int k;
	cin >> k;

	cout << splitArray(nums, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/split-array-largest-sum/description/