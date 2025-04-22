#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<int> nums;
	for (int i = 0; i < total; i++) {
		int buffer;
		cin >> buffer;
		nums.push_back(buffer);
	}

	int k;
	cin >> k;
	cout << countSubarrays(nums, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/		ÄÑ¶È·Ö£º1701