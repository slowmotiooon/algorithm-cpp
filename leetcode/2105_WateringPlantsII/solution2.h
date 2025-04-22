#pragma once

#include <vector>
using namespace std;

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
	int n = plants.size();
	int left = 0, right = n - 1;
	int sum[2] = { capacityA,capacityB };
	int ans = 0;
	while (left < right) {	
		if (sum[0] < plants[left]) {
			ans++;
			sum[0] = capacityA;
		}
		if (sum[1] < plants[right]) {
			ans++;
			sum[1] = capacityB;
		}
		sum[0] -= plants[left];
		sum[1] -= plants[right];
	}
	if (left == right) {
		if (sum[0] > sum[1]) {
			if (sum[0] < plants[left]) {
				ans++;
				sum[0] = capacityA;
			}
			sum[0] -= plants[left];
		}
		else {
			if (sum[1] < plants[right]) {
				ans++;
				sum[1] = capacityB;
			}
			sum[1] -= plants[right];
		}
	}
	return ans;
}

// Í¨¹ý | 113ms | 79.06MB
// O(n) | O(1)