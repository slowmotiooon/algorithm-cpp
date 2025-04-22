#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	cout << maxStrength(nums) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximum-strength-of-a-group/description/?envType=daily-question&envId=2024-09-03		1502