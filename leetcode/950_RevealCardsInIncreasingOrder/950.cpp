#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> deck(n);
    for (int& x : deck) cin >> x;

    vector<int> ans = deckRevealedIncreasing(deck);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/reveal-cards-in-increasing-order 1686
