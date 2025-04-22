#pragma once

#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
	int i = 0;
	for (char c : s) {
		while (i < t.size() && c != t[i]) i++;
		if (i == t.size()) return false;
		i++;
	}
	return true;
}

// Í¨¹ý | 3ms | 7.69MB
// O(n+m) | O(1)