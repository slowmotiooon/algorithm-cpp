#pragma once

#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

vector<int> nextLargerNodes(ListNode* head) {
	vector<int> transformed;
	ListNode* p1 = head;
	for (; p1; p1=p1->next) {
		transformed.push_back(p1->val);
	}
	vector<int> ans(transformed.size());
	stack<int> st;
	st.push(INT_MAX);
	for (int i = transformed.size() - 1; i >= 0; i--) {
		while (transformed[i] >= st.top()) st.pop();
		ans[i] = st.top() == INT_MAX ? 0 : st.top();
		st.push(transformed[i]);
	}
	return ans;
}

// 通过 | 74ms | 44.19MB
// O(n) | O(n)
// 如果一个链表题用数组的方式可解，那么最简单的方法就是转换成数组。