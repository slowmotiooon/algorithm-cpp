#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
	unordered_map<char, vector<int>> ranges;

	for (int i = 0; i < s.size(); i++) {
		ranges[s[i]].push_back(max(abs(points[i][0]), abs(points[i][1])));
	}

	int minVal = INT_MAX;
	for (auto& r : ranges) {
		if (r.second.size() <= 1) continue;
		sort(r.second.begin(), r.second.end());
		minVal = min(minVal, r.second[1]);
	}
	
	int ans = 0;
	for (auto& r : ranges) {
		ans += lower_bound(r.second.begin(), r.second.end(), minVal) - r.second.begin();
	}
	return ans;
}

// 通过 | 223ms | 99.74MB
// O((n+m)*log(m)) m指range中vector的最大数量 | O(n)