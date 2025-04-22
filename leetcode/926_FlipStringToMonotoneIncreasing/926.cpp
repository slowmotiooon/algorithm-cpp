#include <iostream>
#include "solution3.h"
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << minFlipsMonoIncr(s) << endl;
	return 0;
}

// https://leetcode.cn/problems/flip-string-to-monotone-increasing/description/		ÄÑ¶È·Ö£º1602
// tag: #prefixsum, #dp