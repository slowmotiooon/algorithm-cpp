#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> nums1(n1), nums2(n2);
	for (int& i : nums1) {
		cin >> i;
	}
	for (int& i : nums2) {
		cin >> i;
	}
	cout << getCommon(nums1, nums2) << endl;
	return 0;
}

// https://leetcode.cn/problems/minimum-common-value/description/		1250