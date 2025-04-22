#pragma once

#include <string>
using namespace std;

int appendCharacters(string s, string t) {
	int i = 0, j = 0;
	for (; j < t.size();j++) {
		while (i < s.size() && s[i] != t[j]) i++;
		if (i == s.size()) break;
		i++;
	}
	return t.size() - j;
}

// Í¨¹ý | 16ms | 11.88MB
// O(m+n) | O(1)