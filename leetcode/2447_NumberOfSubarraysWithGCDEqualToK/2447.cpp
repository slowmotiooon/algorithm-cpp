#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		nums.push_back(b);
	}

	int k;
	cin >> k;
	cout << subarrayGCD(nums, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/number-of-subarrays-with-gcd-equal-to-k/description/		ÄÑ¶È·Ö£º1603
// tag: #slidingwindow #array #doublepointer #sttable #notcompleted