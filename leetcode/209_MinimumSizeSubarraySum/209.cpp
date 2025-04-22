#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n, target;
	cin >> target >> n;

	vector<int> nums(n);
	for (int& i : nums) {
		cin >> i;
	}
	cout << minSubArrayLen(target, nums) << endl;
	return 0;
}

// https://leetcode.cn/problems/minimum-size-subarray-sum/