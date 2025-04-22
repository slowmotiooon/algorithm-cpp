#pragma once

#include <iostream>
#include <vector>
using namespace std;

constexpr int min(int x, int y) { return x < y ? x : y; }

bool compare(string s1, string s2, string order) {
	for (int i = 0; i < min(s1.length(), s2.length()); i++) {
		if (s1[i] == s2[i]) continue;
		if (order.find(s1[i]) > order.find(s2[i])) return false;
		else return true;
	}
	if (s1.length() > s2.length()) return false;
	else return true;
}

bool isAlienSorted(vector<string>& words, string order) {
	for (int i = 0; i < words.size() - 1; i++) {
		if (!compare(words[i], words[i + 1], order)) return false;
	}
	return true;
}

// 运行结果：
// 通过 | 4ms | 11.96MB
// O(n*m) m为字符串平均长度 | O(1)