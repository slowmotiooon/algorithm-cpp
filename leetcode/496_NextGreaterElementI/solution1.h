#pragma once

#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	stack<int> st;
	st.push(INT_MAX);
	unordered_map<int, int> map;
	for (int i = nums2.size() - 1; i >= 0; i--) {
		while (nums2[i] >= st.top()) st.pop();
		map[nums2[i]] = st.top() == INT_MAX ? -1 : st.top();
		st.push(nums2[i]);
	}
	for (int x : nums1) ans.push_back(map[x]);
	return ans;
}

// Í¨¹ý | 0ms | 12.18MB
// O(n+m) | O(n+m)