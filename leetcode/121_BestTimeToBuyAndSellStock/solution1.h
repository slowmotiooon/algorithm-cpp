#pragma once

#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	int min = 2147483647;
	int result =0;
	for (int i : prices) {
		if (i < min) min = i;
		if (i - min > result) result = i - min;
	}

	return result;
}

// 运行结果：
// 通过 | 94ms | 93.97MB
// O(n) | O(1)
