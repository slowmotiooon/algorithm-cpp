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
	ListNode* newHead = new ListNode();
	ListNode* p1 = head;
	int n = 0;
	while (p1) {
		ListNode* tmp = p1->next;
		p1->next = newHead->next;
		newHead->next = p1;
		p1 = tmp;
		n++;
	}

	vector<int> ans(n);
	stack<int> st;
	newHead = newHead->next;
	st.push(INT_MAX);
	for (int i = n - 1; i >= 0; i--) {
		while (newHead->val >= st.top()) st.pop();
		ans[i] = st.top();
		st.push(newHead->val);
		newHead = newHead->next;
	}

	return ans;
}

// 通过 | 46ms | 39.62MB
// O(n) | O(n)
// 反转链表后，链表的从前向后遍历，就相当于数组的从后向前遍历，然后就可用从后向前的单调栈解决。