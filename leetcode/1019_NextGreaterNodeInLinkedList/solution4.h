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
	stack<pair<int, int>> st;
	vector<int> ans;
	ListNode* p1 = head;
	int i = 0;
	while (p1) {
		while (!st.empty() && p1->val > st.top().second) {
			ans[st.top().first] = p1->val;
			st.pop();
		}
		ans.push_back(0);
		st.push({ i,p1->val });
		i++;
		p1 = p1->next;
	}
	return ans;
}

// 通过 | 96ms | 44.29MB
// O(n) | O(n)
// 思路来源：https://leetcode.cn/problems/next-greater-node-in-linked-list/solutions/2217563/tu-jie-dan-diao-zhan-liang-chong-fang-fa-v9ab
// 正向遍历的单调栈，因为返回值是数组，所以需要维护一个索引值。