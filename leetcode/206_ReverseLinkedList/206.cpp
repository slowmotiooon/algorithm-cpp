#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* next = nullptr) {
        this->val = x;
        this->next = next;
    }
};

class Solution
{
public:
    virtual ListNode* reverseList(ListNode* head) = 0;
};

class Solution1 : public Solution
{
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        vector<ListNode*> nodes;
        for (ListNode* x = head; x != nullptr; x = x->next) { nodes.push_back(x); }
        int n = nodes.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i == 0)
                nodes[i]->next = nullptr;
            else
                nodes[i]->next = nodes[i - 1];
        }
        return nodes[n - 1];
    }
};

int main() {
    ListNode* head =
        new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* result = (new Solution1())->reverseList(head);
    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}