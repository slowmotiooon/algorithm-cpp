#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	vector<int> houses(n1), heaters(n2);
	for (int& i : houses) cin >> i;
	for (int& i : heaters) cin >> i;

	cout << findRadius(houses, heaters) << endl;
	return 0;
}

// https://leetcode.cn/problems/heaters/description/		