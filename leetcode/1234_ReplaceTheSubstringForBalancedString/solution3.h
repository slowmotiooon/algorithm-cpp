#pragma once

#include <string>
using namespace std;

int balancedString(string s) {
	int dict['X'];
	int n = s.size();
	int left = 0;
	int min = n;
	for (char c : s) dict[c]++;
	if (dict['Q'] == n / 4 && dict['W'] == n / 4 && dict['E'] == n / 4 && dict['R'] == n / 4) return 0;
	for (int i = 0; i < n; i++) {
		dict[s[i]]--;
		if (dict['Q'] > n / 4 || dict['W'] > n / 4 || dict['E'] > n / 4 || dict['R'] > n / 4) continue;
		if (min > i - left + 1) min = i - left + 1;
		while (dict['Q'] <= n / 4 || dict['W'] <= n / 4 || dict['E'] <= n / 4 || dict['R'] <= n / 4) {
			if (left == n) break;
			dict[s[left]]++;
			left++;
		}
	}
	return min;
}