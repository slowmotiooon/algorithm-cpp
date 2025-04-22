#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

int minLengthAfterRemovals(vector<int>& nums) {
	unordered_map<int, int> count;
	for (int i : nums) {
		count[i]++;
	}

	while (count.size() > 1) {
		auto maxIt = max_element(count.begin(), count.end(), [&](pair<int, int> a, pair<int, int>b) {return a.second < b.second; });
		auto minIt = min_element(count.begin(), count.end(), [&](pair<int, int> a, pair<int, int>b) {return a.second < b.second; });
		if (maxIt == minIt) minIt++;
		maxIt->second--;
		minIt->second--;
		if (minIt->second == 0) count.erase(minIt);
		if (maxIt->second == 0) count.erase(maxIt);
	}
	if (count.empty()) return 0;
	return count.begin()->second;
}

// 超出时间限制
// 没有利用nums有序的特性
