#pragma once

#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& houses, vector<int>& heaters, int r) {
	for (int i : houses) {
		int sum = 0;
		for (int j : heaters) {
			if (abs(i - j) <= r) {
				sum++;
				break;
			}
		}
		if (!sum) return false;
	}
	return true;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
	int left = 0;
	int right = max(*max_element(houses.begin(), houses.end()) - *min_element(heaters.begin(), heaters.end()), *max_element(heaters.begin(), heaters.end()) - *min_element(houses.begin(), houses.end()));
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(houses, heaters, mid)) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// 超出时间限制
// 看来还是不能图方便，check的时间复杂度达到了O(m*n)，耗时很长。
// 但是算法本身没有错误。