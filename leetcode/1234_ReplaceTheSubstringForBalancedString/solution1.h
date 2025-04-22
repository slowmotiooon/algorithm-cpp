#pragma once

#include <string>
#include <unordered_map>
using namespace std;

int balancedString(string s) {
	int n = s.size();
	unordered_map<int, int> dict;
	dict['Q'] = 0;
	dict['W'] = 0;
	dict['E'] = 0;
	dict['R'] = 0;
	int left = 0, right = n - 1;

	while (left<=right) {
		if (dict[s[left]] >= n / 4) break;
		dict[s[left]]++;
		left++;
	}
	while (left <= right) {
		if (dict[s[right]] >= n / 4) break;
		dict[s[right]]++;
		right--;
	}

	return right - left + 1;
}

// 解答错误
// 原因是把从左往右数的超量字符认定为“必改”，导致出错
// 示例： "WWEQERQWQWWRWWERQWEQ"
// 输出： 6		预期结果： 4