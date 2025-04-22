#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<int> prices;

	for (int i = 0; i < total; i++) {
		int buffer;
		cin >> buffer;
		prices.push_back(buffer);
	}

	cout << maxProfit(prices) << endl;
	return 0;
}

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/