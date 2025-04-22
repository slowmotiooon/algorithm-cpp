#pragma once

#include <vector>
#include <stack>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
	stack<int> st;
	vector<int> ans(prices.size());
	st.push(0);
	for (int i = prices.size() - 1; i >= 0; i--) {
		while (prices[i] < st.top()) st.pop();
		ans[i] = prices[i] - st.top();
		st.push(prices[i]);
	}
	return ans;
}

// 通过 | 7ms | 12.45MB
// O(n) | O(n)
// 单调栈，栈顶到栈底递减