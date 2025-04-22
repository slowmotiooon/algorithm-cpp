#include <iostream>
#include "solution3.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	cout << maxWidthRamp(nums) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximum-width-ramp/description/		1608