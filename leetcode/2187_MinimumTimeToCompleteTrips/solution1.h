#pragma once

#include <vector>
#include <functional>
using namespace std;



long long minimumTime(vector<int>& time, int totalTrips) {
	long long left = 0, right = *min_element(time.begin(), time.end()) * (long long)totalTrips;
	while (left < right) {
		long long mid = left + (right - left) / 2;
		int sum = 0;
		for (int x : time) sum += mid / x;
		if (sum >= totalTrips) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// 通过 | 195ms | 95.04MB
// O(n*log(m*totalTrips)) m为time中的最小值