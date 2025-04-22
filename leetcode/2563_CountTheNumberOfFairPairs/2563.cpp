#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	int lower, upper;
	cin >> lower >> upper;
	cout << countFairPairs(nums, lower, upper) << endl;
	return 0;
}

// https://leetcode.cn/problems/count-the-number-of-fair-pairs/description/		1721