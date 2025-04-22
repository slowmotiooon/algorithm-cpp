#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> times(n);
	for (int i : times) cin >> i;

	int totalTrips;
	cin >> totalTrips;

	cout << minimumTime(times, totalTrips) << endl;
	return 0;
}

// https://leetcode.cn/problems/minimum-time-to-complete-trips/description/		1641