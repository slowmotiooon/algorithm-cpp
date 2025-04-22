#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	vector<vector<int>> nums1(n1), nums2(n2);
	for (auto& i : nums1) {
		int a, b;
		cin >> a >> b;
		i = { a,b };
	}
	for (auto& i : nums2) {
		int a, b;
		cin >> a >> b;
		i = { a,b };
	}

	vector<vector<int>> result = mergeArrays(nums1, nums2);

	for (auto& i : result) {
		cout << i[0] << ' ' << i[1] << ', ';
	}
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values/description/		1281