#pragma once

#include <vector>
#include <string>
using namespace std;

vector<int> ranges;

int check(string s, int mid) {
	int ans = 0;
	bool checked[26] = { false };
	for (int i = 0; i < s.size(); i++) {
		if (ranges[i] > mid) continue;
		else {
			if (!checked[s[i] - 'a']) {
				checked[s[i] - 'a'] = true;
				ans++;
			}
			else return INT_MAX;
		}
	}
	return ans;
}

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
	for (vector<int>& i : points) ranges.push_back(max(abs(i[0]), abs(i[1])));
	int left = 0, right = *max_element(ranges.begin(),ranges.end());
	int ans = INT_MIN;
	while (left <= right) {
		int mid = (left + right) / 2;
		int num = check(s, mid);
		if (num == INT_MAX) right = mid - 1;
		else {
			left = mid + 1;
			ans = max(ans, num);
		}
	}
	return ans;
}

// 通过 | 206ms | 105.63MB
// O(n*log(m)) m为 *max_element(ranges.begin(),ranges.end()) | O(n+A) A为字符种类数，这里为26
// 思路来自：https://leetcode.cn/problems/maximum-points-inside-the-square/solutions/2775310/er-fen-bian-chang-tong-shi-ji-lu-da-an-z-92w5
