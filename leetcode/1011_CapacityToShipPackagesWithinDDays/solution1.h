#pragma once

#include <vector>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
	int right = 0;
	for (int x : weights) right += x;
	int left = *max_element(weights.begin(), weights.end());
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int sum = 0;
		int ships = 0;
		for (int x : weights) {
			if (sum + x > mid) {
				ships++;
				sum = x;
			}
			else sum += x;
		}
		if (ships + 1 <= days) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// 通过 | 43ms | 33.04MB
// O(n*log(m)) m为weights总和与weights最大值的差 | O(1)