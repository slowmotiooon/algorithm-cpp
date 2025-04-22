#pragma once

#include <string>
using namespace std;

int minimumLength(string s) {
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left] != s[right]) return right - left + 1;
		char current = s[left];
		while (left < s.size() && s[left] == current) left++;
		while (0 <= right && s[right] == current) right--;
	}
	if (left == right) return 1;
	return 0;
}

// Í¨¹ý | 25ms | 13.94MB
// O(n) | O(1)