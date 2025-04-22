#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	vector<int> staple(n1), drinks(n2);
	for (int& i : staple) cin >> i;
	for (int& i : drinks) cin >> i;

	int x;
	cin >> x;

	cout << breakfastNumber(staple, drinks, x) << endl;
	return 0;
}

// https://leetcode.cn/problems/2vYnGI/description/