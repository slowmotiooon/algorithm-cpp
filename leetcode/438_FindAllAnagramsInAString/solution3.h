#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
	if (p.length() > s.length()) return {};
	
	unordered_map<char, int> pDict, sDict;
	vector<int> result;

	for (char c : p) pDict[c]++;

	for (int i = 0; i < s.length(); i++) {
		sDict[s[i]]++;
		if (i < p.length() - 1) continue;

		if (sDict == pDict) result.push_back(i - p.length() + 1);
		sDict[s[i - p.length() + 1]]--;
		if (sDict[s[i - p.length() + 1]] == 0) sDict.erase(s[i - p.length() + 1]);
	}
	
	return result;
}

// 运行结果：
// 通过 | 45ms | 15.05MB
// 参照题解 https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/2882233/hua-dong-chuang-kou-tao-lu-by-ysmagixgds-8co3
// 这种滑动窗口的算法比较易懂一些。