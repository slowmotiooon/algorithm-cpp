#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

double getHash(string s) {
	double result = 1.0;
	if (s.length() == 0) return 0.0;
	for (char i : s) {
		result *= (i / 64.0);
	}
	return result;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	if (strs.size() == 0) return { {} };
	if (strs.size() == 1) return { strs };
	unordered_map<double, vector<string>> list;
	for (string item : strs) {
		list[getHash(item)].push_back(item);
	}

	vector<vector<string>> result;
	for (auto item : list) {
		result.push_back(item.second);
	}
	return result;
}

// 运行结果：
// 失败，通过125/126个测试样例。
// 最后一个测试样例是一个11万字符的超大数据，难以处理。