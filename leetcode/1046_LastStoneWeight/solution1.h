#pragma once

#include <queue>
#include <vector>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> heap;
    for (int x : stones) heap.push(x);
    while (heap.size() >= 2) {
        int val1 = heap.top();
        heap.pop();
        int val2 = heap.top();
        heap.pop();
        if (val1 != val2) heap.push(abs(val1 - val2));
    }
    return heap.empty() ? 0 : heap.top();
}

// 通过 | 0ms | 9.87MB
// O(n*logn) | O(n) 因为优先队列的底层是二叉树，因此时间复杂度是O(n*logn)