#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> customers(n), grumpy(n);

	for (int i = 0; i < n; i++) cin >> customers[i];
	for (int i = 0; i < n; i++) cin >> grumpy[i];

	int minutes;
	cin >> minutes;

	cout << maxSatisfied(customers, grumpy, minutes) << endl;
	return 0;
}

// https://leetcode.cn/problems/grumpy-bookstore-owner/description/		1418
// tag: #slidingwindow