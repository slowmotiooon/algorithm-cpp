#pragma once

#include <vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
	int n = customers.size();
	int sum = 0;

	for (int i = 0; i < n; i++){
		if (!grumpy[i]) sum += customers[i];
	}
	int max = sum;
	for (int i = 0; i < n; i++) {
		if(grumpy[i]) sum += customers[i];
		if (i < minutes - 1) continue;
		if (sum > max) max = sum;
		if (grumpy[i - minutes + 1]) sum -= customers[i - minutes + 1];
	}
	return max;
}

// Í¨¹ý | 32ms | 33.82MB
// O(n) | O(1)