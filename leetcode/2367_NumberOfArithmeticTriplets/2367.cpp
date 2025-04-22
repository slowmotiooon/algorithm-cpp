#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	int diff;
	cin >> diff;

	cout << arithmeticTriplets(nums, diff) << endl;
	return 0;
}

// https://leetcode.cn/problems/number-of-arithmetic-triplets/description/		1203