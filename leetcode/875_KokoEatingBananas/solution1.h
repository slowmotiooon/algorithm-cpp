#pragma once

#include <vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
	int left = 1, right = *max_element(piles.begin(), piles.end());
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int sum = 0;
		for (int x : piles) sum += x / mid + (x % mid != 0);
		if (sum <= h) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// Í¨¹ý | 32ms | 21.15MB
// O(n*log(m)) mÎª*max_element(piles.begin(), piles.end()) | O(1)