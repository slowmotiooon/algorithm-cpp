#pragma once

#include <string>
using namespace std;

string clearDigits(string s) {
	string ans;
	int status = 0;
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		if (isdigit(*it)) status++;
		else if (isalpha(*it)) {
			if (status) status--;
			else ans = *it + ans;
		}
	}
	return ans;
}

// 通过 | 5ms | 8.09MB
// O(n) | O(1)
// 反向迭代器版