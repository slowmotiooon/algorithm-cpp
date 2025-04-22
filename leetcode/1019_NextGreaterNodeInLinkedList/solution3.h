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

vector<int> ans;
stack<int> st;
void f(ListNode* p, int i) {
	if (!p) {
		ans.resize(i);
		return;
	}
	f(p->next, i + 1);
	while (p->val >= st.top()) st.pop();
	ans[i] = st.top() == INT_MAX ? 0 : st.top();
	st.push(p->val);
}

vector<int> nextLargerNodes(ListNode* head) {
	st.push(INT_MAX);
	f(head, 0);
	return ans;
}

// 通过 | 338ms | 47.38MB
// O(n) | O(n)	主要开销递归函数的栈开销上