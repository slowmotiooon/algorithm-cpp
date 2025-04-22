#pragma once

#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	stack<int> st;
	vector<int> range(n);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && height[i] >= height[st.top()]) st.pop();
		range[i] = st.empty() ? n : st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = 0; i < n; i++) {
		while (!st.empty() && height[i] > height[st.top()]) st.pop();
		int tmp = st.empty() ? -1 : st.top();
		if (range[i] != n && tmp != -1) ans = (min(height[tmp], height[range[i]]) - height[i]) * (range[i] - tmp - 1) + ans;
		st.push(i);
	}
	return ans;
}

// 通过 | 32ms | 25.85MB
// O(n) | O(n)
// 单调栈，先找右界，再找左界（防止重复，右界是严格大，左界是大于等于）