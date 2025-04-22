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

	cout << maximumLength(nums, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-i/description/?envType=daily-question&envId=2024-09-06		1849