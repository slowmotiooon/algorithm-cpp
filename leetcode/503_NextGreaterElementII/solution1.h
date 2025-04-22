#pragma once

#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	stack<int> st;
	vector<int> ans(n);
	st.push(INT_MAX);
	for (int i = n * 2 - 1; i >= 0; i--) {
		while (nums[i % n] >= st.top()) st.pop();
		if (i < n) ans[i] = st.top() == INT_MAX ? -1 : st.top();
		st.push(nums[i % n]);
	}
	return ans;
}

// Í¨¹ý | 34ms | 26.29MB
// O(n) | O(n)
