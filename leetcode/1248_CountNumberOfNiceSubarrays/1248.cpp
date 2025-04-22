#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	int k;
	cin >> k;

	cout << numberOfSubarrays(nums, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/count-number-of-nice-subarrays/description/		1624