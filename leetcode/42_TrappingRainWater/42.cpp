#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> height(n);
	for (int& i : height) cin >> i;

	cout << trap(height) << endl;
	return 0;
}

// https://leetcode.cn/problems/trapping-rain-water/description/