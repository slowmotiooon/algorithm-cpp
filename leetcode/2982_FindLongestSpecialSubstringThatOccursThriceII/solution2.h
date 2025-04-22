#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int maximumLength(string s) {
	vector<int> groups[26];
	char current = '\0';
	for (char c : s) {
		if (c != current) {
			current = c;
			groups[c - 'a'].push_back(1);
		}
		else groups[c - 'a'].back()++;
	}

	int maxVal = 0;
	for (vector<int>& l : groups) {
		if (l.empty()) continue;
		sort(l.rbegin(), l.rend());
		l.push_back(0);
		l.push_back(0);
		maxVal = max({maxVal,l[0]-2,min(l[0]-1,l[1]),l[2]});
	}
	return maxVal ? maxVal : -1;
}

// 通过 | 205ms | 51.80MB
// O(n*log(n)) | O(n)
// 思路来自：https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/solutions/2585801/fen-lei-tao-lun-jian-ji-xie-fa-pythonjav-671l