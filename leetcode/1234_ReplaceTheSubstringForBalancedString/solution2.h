#pragma once

#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> dict;

int balancedString(string s) {
	int n = s.size();
	dict['Q'] = n / 4;
	dict['W'] = n / 4;
	dict['E'] = n / 4;
	dict['R'] = n / 4;
	auto judge = [&]() { return dict['Q'] >= 0 && dict['W'] >= 0 && dict['E'] >= 0 && dict['R'] >= 0; };

	for (char c : s) {
		dict[c]--;
	}
	int left = 0, right = 0;
	int min = n;
	if (judge()) return 0;

	unordered_map<char, bool> enable;
	enable['Q'] = dict['Q'] >= 0;
	enable['W'] = dict['W'] >= 0;
	enable['E'] = dict['E'] >= 0;
	enable['R'] = dict['R'] >= 0;

	while (right < n) {
		while (right < n && !judge()) {
			dict[s[right]]++;
			right++;
		}
		//if (right == n && !judge()) return min;
		if (min > right - left) min = right - left;
		while (left < right && dict[s[left]] >= 0) {
			if (min > right - left && enable[s[left]]) min = right - left;
			dict[s[left]]--;
			left++;
		}
	}
	return min;
}

// 解答错误
// 感觉差一点就能通过。