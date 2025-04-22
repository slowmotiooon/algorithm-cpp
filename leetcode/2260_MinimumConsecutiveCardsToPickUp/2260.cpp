#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int& x : cards) cin >> x;

    cout << minimumCardPickup(cards) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up/description/       1365