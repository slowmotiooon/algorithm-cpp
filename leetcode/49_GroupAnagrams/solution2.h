#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	if (strs.size() == 0) return { {} };
	if (strs.size() == 1) return { strs };
	unordered_map<string, vector<string>> list;
	for (string item : strs) {
		string buffer = item;
		sort(item.begin(), item.end());
		list[item].push_back(buffer);
	}

	vector<vector<string>> result;
	for (auto item : list) {
		result.push_back(item.second);
	}
	return result;
}

// 运行结果：
// 通过 | 36ms | 24.64MB
// solution1与solution2最大的区别就是哈希表的键值，在此方法中键值为字符串，而不是字符串解析成的数字。