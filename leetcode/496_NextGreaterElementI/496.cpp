#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;


	vector<int> nums1(n1), nums2(n2);
	for (int& i : nums1) cin >> i;
	for (int& i : nums2) cin >> i;

	vector<int> result = nextGreaterElement(nums1, nums2);
	for (int i : result) cout << i << ' ';
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/next-greater-element-i/description/