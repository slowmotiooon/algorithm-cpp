#pragma once

#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	vector<int> range(n);
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
		range[i] = st.empty() ? n : st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
		range[i] = range[i]-(st.empty() ? -1 : st.top())-1;
		if (ans < range[i] * heights[i]) ans = range[i] * heights[i];
		st.push(i);
	}

	return ans;
}

// 通过 | 129ms | 22.34MB
// O(n) | O(n)
// 思路：	求柱状图中的最大矩形
// ->		遍历每个柱形，求其能向两侧延展的最大宽度，再乘以该柱形高度以获得面积，取最大值
// ->		找到每个柱形左侧和右侧第一个高度比它小的柱形，以获得延展的范围。