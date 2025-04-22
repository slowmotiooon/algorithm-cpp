#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	cout << shortestBeautifulSubstring(s, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/description/		1483