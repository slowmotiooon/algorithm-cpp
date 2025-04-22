#pragma once

#include <string>
using namespace std;

string shortestBeautifulSubstring(string s, int k) {
	int n = s.size();
	int cur = 0;
	int left = 0, right = 0;
	int min = INT_MAX;
	int minIndex = -1;
	auto judgeMin = [&](int i1, int i2) {
		for (int i = 0; i < min; i++) {
			if (s[i1+i] == s[i2+i]) continue;
			else return s[i1+i] < s[i2+i] ? i1 : i2;
		}
		return i1;
	};
	while (right < n) {
		while (right < n && cur != k) {
			cur += s[right] & 1;
			right++;
		}
		if (right == n && left == 0 && cur < k) return "";
		while (left < right && cur == k) {
			if (right - left <= min) {
				if (min == right - left) minIndex = judgeMin(minIndex, left);
				else minIndex = left;
				min = right - left;
			}
			cur -= s[left] & 1;
			left++;
		}
	}
	return s.substr(minIndex, min);
}

// Í¨¹ý | 0ms | 7.96MB
// O(n^2) | O(1)