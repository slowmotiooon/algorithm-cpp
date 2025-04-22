#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int maxCost;
	cin >> maxCost;
	cout << equalSubstring(s, t, maxCost) << endl;
	return 0;
}

// https://leetcode.cn/problems/get-equal-substrings-within-budget/description/		1497