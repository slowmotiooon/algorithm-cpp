#pragma once

#include <iostream>
using namespace std;

int minFlipsMonoIncr(string s) {
	int operation = 0;
	int minVal = 0;
	int zeroes = 0;
	int i = 0;
	while (i < s.size() && s[i] != '1') i++;

	for (; i < s.size(); i++) {
		if (s[i] == '1') operation++;
		else {
			operation--;
			zeroes++;
		}
		if (minVal > operation) minVal = operation;
	}
	return zeroes + minVal;
}

// 运行结果：
// 通过 | 24ms | 12.35MB
// O(n) | O(1)
// solution2 经过优化后的算法，只需要一次遍历。