#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
    vector<int> q;
    int size = 0;
    int f = 0, r = 0;

public:
    MyCircularQueue(int k) {
        q = vector<int>(k);
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        q[r++ % size] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        f++;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[f % size];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[(r - 1) % size];
    }

    bool isEmpty() { return f == r; }

    bool isFull() { return f % size == r % size && f != r; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// 通过 | 0ms | 23.14MB
