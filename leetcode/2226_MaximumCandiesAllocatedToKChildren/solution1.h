#pragma once

#include <vector>
using namespace std;

int maximumCandies(vector<int>& candies, long long k) {
	long long sum = 0;
	for (int x : candies) sum += x;
	if (sum < k) return 0;

	int right = 1, left = *max_element(candies.begin(), candies.end());
	while (left >= right) {
		int mid = right + (left - right) / 2;
		long long total = 0;
		for (int x : candies) total += x / mid;
		if (total >= k) right = mid + 1;
		else left = mid - 1;
	}
	return left;
}

// Í¨¹ý | 125ms | 84.90MB
// O(n*log(m)) mÎª*max_element(candies.begin(), candies.end()) | O(1)