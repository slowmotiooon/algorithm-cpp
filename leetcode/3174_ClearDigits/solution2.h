#pragma once

#include <string>
using namespace std;

string clearDigits(string s) {
	string ans;
	for (char c : s) {
		if (isdigit(c)) ans.pop_back();
		else ans += c;
	}
	return ans;
}

// 通过 | 8ms | 7.90MB
// O(n) | O(1)
// 思路来源：https://leetcode.cn/problems/clear-digits/solutions/2805250/on-yong-zhan-wei-hu-pythonjavacgo-by-end-223b
// 使用栈维护ans
