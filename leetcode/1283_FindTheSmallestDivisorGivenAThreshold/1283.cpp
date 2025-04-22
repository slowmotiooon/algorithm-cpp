#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	int threshold;
	cin >> threshold;

	cout << smallestDivisor(nums, threshold) << endl;
	return 0;
}

// https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/description/		1542