#include <deque>
using namespace std;

class Checkout
{
    deque<int> d, r;

public:
    Checkout() {}

    int get_max() { return r.empty() ? -1 : d.front(); }

    void add(int value) {
        while (!d.empty() && d.back() < value) d.pop_back();
        d.push_back(value);
        r.push_back(value);
    }

    int remove() {
        if (d.empty()) return -1;
        int ans = r.front();
        if (r.front() == d.front()) d.pop_front();
        r.pop_front();
        return ans;
    }
};

// 通过 | 33ms | 62.00MB