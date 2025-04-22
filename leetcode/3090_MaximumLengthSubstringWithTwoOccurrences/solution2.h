#pragma once

#include <vector>
#include <string>
using namespace std;

int maximumLengthSubstring(string s) {
	int left = 0; 
	int right = 0;
	int count[26] = { 0 };
	int max = 0;
	while (right < s.size() && left < s.size()) {
		count[s[right] - 'a']++;
		while (count[s[right] - 'a'] > 2) {
			count[s[left] - 'a']--;
			left++;
		}
		right++;
		if (right - left > max) max = right - left;
	}
	return max;
}

// 通过 | 0ms | 8.60MB
// O(n+m) | O(m) 在此处m=26
// 思路来自：https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/solutions/2704776/on-hua-dong-chuang-kou-pythonjavacgo-by-hl44d