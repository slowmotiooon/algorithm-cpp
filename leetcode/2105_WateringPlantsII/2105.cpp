#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> plants(n);
	for (int& i : plants) {
		cin >> i;
	}

	int a, b;
	cin >> a >> b;
	cout << minimumRefill(plants, a, b) << endl;
	return 0;
}

// https://leetcode.cn/problems/watering-plants-ii/description/		1507