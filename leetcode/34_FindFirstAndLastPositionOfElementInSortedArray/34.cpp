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
	
	vector<int> result = searchRange(nums, k);

	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/		