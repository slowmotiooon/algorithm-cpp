#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> heights(n);
	for (int& i : heights) cin >> i;

	cout << largestRectangleArea(heights) << endl;
	return 0;
}

// https://leetcode.cn/problems/largest-rectangle-in-histogram/description/