#pragma once

#include <string>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
	int left = 0, right = 0;
	int current = 0;
	auto abs = [&](int a, int b) {return a > b ? a - b : b - a; };
	int max = 0;
	while (right < s.size()) {
		current += abs(s[right], t[right]);
		right++;
		while (current > maxCost) {
			current -= abs(s[left], t[left]);
			left++;
		}
		if (max < right - left) max = right - left;
	}
	return max;
}

// Í¨¹ý | 7ms | 8.77MB
// O(n) | O(1)