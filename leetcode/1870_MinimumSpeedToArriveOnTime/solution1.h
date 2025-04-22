#pragma once

#include <vector>
using namespace std;

int minSpeedOnTime(vector<int>& dist, double hour) {
	if (hour <= dist.size() - 1) return -1;
	int left = 1, right = max(*max_element(dist.begin(), dist.end()), dist.back() * 100);
	while (left <= right) {
		int mid = left + (right - left) / 2;
		double sum = 0;
		for (int i = 0; i < dist.size() - 1; i++) sum += dist[i] / mid + (dist[i] % mid != 0);
		sum += (double)dist[dist.size() - 1] / mid;
		if (sum <= hour) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// 通过 | 175ms | 101.76MB
// O(n*log(m)) m为 max(*max_element(dist.begin(), dist.end()), dist.back() * 100) | O(1)
// 主要突破口在于找到二分查找的上界。
// 由于double可能会带来误差，所以避免浮点运算可以进一步优化程序。