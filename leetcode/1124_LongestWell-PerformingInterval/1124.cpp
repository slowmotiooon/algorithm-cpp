#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> hours(n);
	for (int& i : hours) cin >> i;

	cout << longestWPI(hours) << endl;
	return 0;
}

// https://leetcode.cn/problems/longest-well-performing-interval/description/		1908
// notcompleted