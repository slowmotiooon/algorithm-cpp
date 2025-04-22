#pragma once

#include <vector>
#include <string>
using namespace std;

extern int f(string s);

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
	vector<int> count(12);
	vector<int> ans;
	for (string s : words) count[f(s)]++;
	for (int i = 9; i >= 0; i--) count[i] += count[i + 1];
	for (string s : queries) ans.push_back(count[f(s) + 1]);	// 因此count的个数为12（最大索引为11）
	return ans;
}

// 通过 | 12ms | 14.86MB
// O((n+m)*p) p为字符串最长长度 | O(1)
// 哈希表+前缀和
// 比二分查找少了需要操作次数和空间开销，尤其是排序。