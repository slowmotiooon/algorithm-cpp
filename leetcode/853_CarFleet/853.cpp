#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int target;
	cin >> target;

	int n;
	cin >> n;

	vector<int> position(n), speed(n);
	for (int& i : position) cin >> i;
	for (int& i : speed) cin >> i;

	cout << carFleet(target, position, speed) << endl;
	return 0;

}

// https://leetcode.cn/problems/car-fleet/description/		1678
