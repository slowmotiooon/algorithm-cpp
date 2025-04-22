#pragma once

#include <vector>
using namespace std;

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
	int n = plants.size();
	int sumA = 0, sumB = 0;
	int ans = 0;
	for (int i = 0; i < n / 2; i++) {
		sumA += plants[i];
		sumB += plants[n - 1 - i];
	}
	
	if (n & 1) sumA% capacityA > sumB% capacityB ? sumA += plants[n / 2] : sumB += plants[n / 2];
	ans = sumA / capacityA + sumB / capacityB;
	if (sumA % capacityA == 0) ans--;
	if (sumB % capacityB == 0) ans--;
	return ans;
}

// 解答错误
// 果然硬算不行吗？