#pragma once

#include <vector>
using namespace std;

bool isEqual(int* n1, int* n2) {
	for (int i = 0; i < 26; i++) {
		if (n1[i] != n2[i]) return false;
	}
	return true;
}

vector<int> findAnagrams(string s, string p) {
	if (p.length() > s.length())return {};

	vector<int> result;

	int pDict[26] = {0};
	for (char c : p) {
		pDict[c - 97]++;
	}

	for (int i = 0; i <= s.length() - p.length(); i++) {
		string sub = s.substr(i, p.length());
		int sDict[26] = {0};
		for (char c : sub) {
			sDict[c - 97]++;
		}
		if (isEqual(pDict, sDict)) result.push_back(i);
	}
	return result;
}

// 运行结果：
// 通过 | 540ms | 281.10MB
// 优化空间其实特别大，循环特别多，如何判断两个字串相等也可以优化