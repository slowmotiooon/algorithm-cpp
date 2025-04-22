#include <deque>
#include <vector>
using namespace std;

class FrontMiddleBackQueue
{
    deque<int> f;
    deque<int> e;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        f.push_front(val);
        if (f.size() > e.size()) {
            e.push_front(f.back());
            f.pop_back();
        }
    }

    void pushMiddle(int val) {
        if (f.size() == e.size())
            e.push_front(val);
        else
            f.push_back(val);
    }

    void pushBack(int val) {
        e.push_back(val);
        if (e.size() - f.size() > 1) {
            f.push_back(e.front());
            e.pop_front();
        }
    }

    int popFront() {
        if (e.empty())
            return -1;
        else if (f.empty()) {
            int x = e.front();
            e.pop_front();
            return x;
        }
        int x = f.front();
        f.pop_front();
        if (e.size() - f.size() > 1) {
            f.push_back(e.front());
            e.pop_front();
        }
        return x;
    }

    int popMiddle() {
        if (e.empty()) return -1;
        int m = 0;
        if (f.size() == e.size()) {
            m = f.back();
            f.pop_back();
        }
        else {
            m = e.front();
            e.pop_front();
        }
        return m;
    }

    int popBack() {
        if (e.empty()) return -1;
        int x = e.back();
        e.pop_back();
        if (e.size() < f.size()) {
            e.push_front(f.back());
            f.pop_back();
        }
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

// 通过 | 9ms | 26.78MB
