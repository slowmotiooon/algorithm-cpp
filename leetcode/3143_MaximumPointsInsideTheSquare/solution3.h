#pragma once

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
	pair<int, int> ranges[26];
	for (pair<int, int>& i : ranges) i = { INT_MAX,INT_MAX };

	int minVal = INT_MAX;
	for (int i = 0; i < s.size(); i++) {
		int val = max(abs(points[i][0]), abs(points[i][1]));
		if (val <= ranges[s[i] - 'a'].first) {
			ranges[s[i] - 'a'].second = ranges[s[i] - 'a'].first;
			ranges[s[i] - 'a'].first = val;
		}
		else if (val <= ranges[s[i] - 'a'].second) {
			ranges[s[i] - 'a'].second = val;
		}
		minVal = min(minVal, ranges[s[i] - 'a'].second);
	}

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int val = max(abs(points[i][0]), abs(points[i][1]));
		if (val < minVal) ans++;
	}

	return ans;
}

// 通过 | 195ms | 96.30MB
// O(n+A) | O(A) A为字符种类，此处A=26
// 思路来源：https://leetcode.cn/problems/maximum-points-inside-the-square/solutions/2775310/er-fen-bian-chang-tong-shi-ji-lu-da-an-z-92w5 方法二