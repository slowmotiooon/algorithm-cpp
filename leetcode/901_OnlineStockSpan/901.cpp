#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	StockSpanner* sp = new StockSpanner();

	while (1) {
		int val;
		cin >> val;
		sp->next(val);
	}
	return 0;
}

// https://leetcode.cn/problems/online-stock-span/		1709