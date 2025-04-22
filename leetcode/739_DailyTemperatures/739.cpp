#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> temperatures(n);
	for (int& i : temperatures) cin >> i;
	vector<int> result = dailyTemperatures(temperatures);
	for (int i : result) cout << i << ", ";
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/daily-temperatures/description/