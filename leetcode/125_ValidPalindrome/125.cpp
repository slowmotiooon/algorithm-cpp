#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	string s;
	getline(cin, s);
	cout << isPalindrome(s) << endl;
	return 0;
}

// https://leetcode.cn/problems/valid-palindrome/description/