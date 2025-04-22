#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> findAnagrams(string s, string p) {
	if (p.length() > s.length()) return {};

	vector<int> result;
	sort(p.begin(), p.end());

	for (int i = 0; i <= s.length() - p.length(); i++) {
		string sub = s.substr(i, p.length());
		sort(sub.begin(), sub.end());
		if (sub == p) result.push_back(i);
	}
	return result;
}

// 运行结果： 超出时间限制
// 本质上跟第一种方法一样，没想到sort比哈希表遍历用的时间都长