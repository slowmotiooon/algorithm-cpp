#include<iostream>
#include "solution1.h"
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	cout << isSubsequence(s, t) << endl;
	return 0;
}

// https://leetcode.cn/problems/is-subsequence/description/		