#pragma once

#include <vector>
using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
	int count = 0;
	for (int i = 0; i < startTime.size(); i++) {
		if (queryTime <= endTime[i] && queryTime >= startTime[i]) count++;
	}
	return count;
}

// Í¨¹ý | 4ms | 13.18MB
// O(n) | O(1)
