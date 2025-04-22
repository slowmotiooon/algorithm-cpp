#pragma once

#include <iostream>
using namespace std;

constexpr int min(int& x, int& y) { return x < y ? x : y; }

int minFlipsMonoIncr(string s) {
	int dp0 = 0, dp1 = 0;
	for (char c : s) {
		if (c == '0') dp1 = min(dp0, dp1) + 1;
		else {
			dp1 = min(dp0, dp1);
			dp0++;
		}
	}
	return min(dp0, dp1);
}

// 通过 | 24ms | 12.39MB
// O(n) | O(1)
// 思路来源：https://leetcode.cn/problems/flip-string-to-monotone-increasing/solutions/2782512/yi-ti-si-jie-qian-zhui-he-dp-zhan-lis-by-plpf	方法二
// 思路：使用动态规划
// dp0 ：当前字符串以0结尾实现递增的最小反转次数
// dp1 ：当前字符串以1结尾实现递增的最小反转次数
// 示例：		1	0	0	1	1	1	1	1	1	1	0	0	1	0	1	1	1	0	1	1
// dp0		0	1	1	1	2	3	4	5	6	7	8	8	8	9	9	10	11	12	12	13	14
// dp1		0	0	1	2	1	1	1	1	1	1	1	2	3	3	4	4	4	4	5	5	5
// return min(dp1, dp0); (= 5) 
// 重点在于理解此处的转移函数