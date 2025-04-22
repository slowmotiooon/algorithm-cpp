#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	cout << minLengthAfterRemovals(nums) << endl;
	return 0;
}

// https://leetcode.cn/problems/minimum-array-length-after-pair-removals/description/		1750