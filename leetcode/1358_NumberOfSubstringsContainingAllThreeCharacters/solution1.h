#pragma once

#include <string>
using namespace std;

int numberOfSubstrings(string s) {
	int n = s.size();
	int left = 0;
	int count[3] = { 0 };
	int ans = 0;
	for (int i = 0; i < n; i++) {
		count[s[i] - 'a']++;
		while (count[0] && count[1] && count[2]) {
			if (count[0] && count[1] && count[2]) ans += n - i;
			count[s[left] - 'a']--;
			left++;
		}
	}
	return ans;
}

// Í¨¹ý | 18ms | 9.72MB
// O(n) | O(1)