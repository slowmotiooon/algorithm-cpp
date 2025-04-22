#include <iostream>
#include "solution4.h"
using namespace std;

int main() {
	ListNode* head = new ListNode(2, new ListNode(7, new ListNode(4, new ListNode(3, new ListNode(5)))));
	vector<int> result = nextLargerNodes(head);
	for (int i : result) cout << i << ' ';
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/next-greater-node-in-linked-list/description/