#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque
{
    vector<int> q;
    int f = 10000, r = 10000;
    int size = 0;

public:
    MyCircularDeque(int k) {
        q = vector<int>(k);
        size = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        q[(--f) % size] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        q[(r++) % size] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        f++;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        r--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : q[f % size]; }

    int getRear() { return isEmpty() ? -1 : q[(r - 1) % size]; }

    bool isEmpty() { return f == r; }

    bool isFull() { return f % size == r % size && f != r; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

// 通过 | 6ms | 24.15MB