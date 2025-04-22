struct FwdListNode {
    int val;
    FwdListNode* next;
    FwdListNode (int x = 0, FwdListNode* p = nullptr) {
        val = x;
        next = p;
    }
};

struct DoubleListNode {
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode (int x = 0, DoubleListNode* n = nullptr, DoubleListNode* p = nullptr) {
        val = x;
        next = n;
        prev = p;
    }
};
