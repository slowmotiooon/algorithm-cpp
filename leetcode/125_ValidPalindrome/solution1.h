#pragma once

#include <string>
using namespace std;

bool isPalindrome(string s) {
	int left = 0, right = s.size() - 1;
	auto isAlpha = [&](char c) {
		if (c > 96 && c <= 96 + 26) return c;
		if (c > 64 && c <= 64 + 26) return char(c + 32);
		if (c >= '0' && c <= '9') return c;
		else return '\0';
	};
	while (left < right) {
		while (left<s.size() && !isAlpha(s[left])) left++;
		while (right>=0 && !isAlpha(s[right])) right--;
		if (left > right) return true;
		if (isAlpha(s[left]) != isAlpha(s[right])) return false;
		left++;
		right--;
	}
	return true;
}

// 通过 | 4ms | 8.71MB
// O(n) | O(1)
// 相向双指针