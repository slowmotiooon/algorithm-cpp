#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> weights(n);
	for (int& i : weights) cin >> i;

	int days;
	cin >> days;

	cout << shipWithinDays(weights, days) << endl;
	return 0;

}

// https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/description/		1725