#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	RangeFreqQuery* rf = new RangeFreqQuery(nums);

	while (1) {
		int left, right, value;
		cin >> left >> right >> value;
		cout<<rf->query(left, right, value);
	}

	return 0;
}

// https://leetcode.cn/problems/range-frequency-queries/description/		1702