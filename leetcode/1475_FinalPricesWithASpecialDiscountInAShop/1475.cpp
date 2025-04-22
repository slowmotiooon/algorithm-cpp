#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> prices(n);
	for (int& i : prices) cin >> i;

	vector<int> result = finalPrices(prices);
	for (int i : result) cout << i << ", ";
	cout << endl;
	return 0;

}

// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/description/		1212