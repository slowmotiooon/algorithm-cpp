#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> quantities(k);
	for (int& i : quantities) cin >> i;

	cout << minimizedMaximum(n, quantities) << endl;
	return 0;
}

// https://leetcode.cn/problems/minimized-maximum-of-products-distributed-to-any-store/description/		1886