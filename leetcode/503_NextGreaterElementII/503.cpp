#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;

	vector<int> result = nextGreaterElements(nums);
	for (int x : result) cout << x << ' ';
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/next-greater-element-ii/description/