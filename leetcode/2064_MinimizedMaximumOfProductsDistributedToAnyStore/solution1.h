#pragma once

#include <vector>
#include <numeric>
using namespace std;

int minimizedMaximum(int n, vector<int>& quantities) {
	int left = 1, right = *max_element(quantities.begin(), quantities.end());
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int count = 0;
		for (int x : quantities) count += x / mid + (x % mid != 0);
		if (count >= n) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// Í¨¹ý | 140ms | 85.28MB
// O(n*log(m)) mÎª*max_element(quantities.begin(), quantities.end() | O(1)