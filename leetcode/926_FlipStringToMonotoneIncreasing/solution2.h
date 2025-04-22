#pragma once

#include <iostream>
using namespace std;

int minFlipsMonoIncr(string s) {
	int i = 0;
	int count = 0;
	while (i < s.size() && !(s[i] - 48)) i++;
	int state = i;
	for (; i < s.size(); i++) {
		count += s[i] - 48 == 0;
	}

	int minCount = INT_MAX;

	while (state<s.size()) {
		if (s[state] == '1') {
			if (state) {
				if (minCount > count) minCount = count;
			}
			else if(s[state-1]=='0') if (minCount > count) minCount = count;
		}
		if (s[state] == '1') count++;
		else count--;
		state++;
	}
	return minCount < count ? minCount : count;
}

// 运行结果：
// 通过 | 23ms | 13.32MB
// O(n) | O(1)
// 双指针？
// 思路：	示例：10011111110010111011
// 第一次循环：找到第一个1所在的位置，计算count
//						1	0	0	1	1	1	1	1	1	1	0	0	1	0	1	1	1	0	1	1
//						|	1	2								3	4		5				6				count = 6;
// 第二次循环，变动count，计算最小值minCount
//						|																					count = 6;	minCount = 6;
//						+1	-1	-1	|																		count = 5;	minCount = 5;
//									+1	+1	+1	+1	+1	+1	+1	-1	-1	|									count = 10;	minCount = 5;
//																		+1	-1	|							count = 10;	minCount = 5;
//																				+1	+1	+1	-1	|			count = 12;	minCount = 5;
//																								+1	+1		count = 14; minCount = 5;
// question：能不能只用一次遍历？