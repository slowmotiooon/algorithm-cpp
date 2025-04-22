#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dist(n);
	for (int& i : dist) cin >> i;

	double hour;
	cin >> hour;

	cout << minSpeedOnTime(dist, hour) << endl;
	return 0;
}

// https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/description/		1676