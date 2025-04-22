#pragma once

#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> result(temperatures.size());
	stack<int> stack1;
	for (int i = temperatures.size() - 1; i >= 0; i--) {
		while (!stack1.empty() && temperatures[i] >= temperatures[stack1.top()]) stack1.pop();
		if (!stack1.empty()) result[i] = stack1.top() - i;
		stack1.push(i);
	}
	return result;
}

// 通过 | 115ms | 98.82MB
// O(n) | O(n)
// 思路来自：https://leetcode.cn/problems/daily-temperatures/solutions/2470179/shi-pin-jiang-qing-chu-wei-shi-yao-yao-y-k0ks
// 单调栈题单第一题