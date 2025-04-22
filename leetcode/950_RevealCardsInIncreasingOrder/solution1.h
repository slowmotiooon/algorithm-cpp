#pragma once

#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    vector<int> ans;
    deque<int> q;
    sort(deck.begin(), deck.end(), [](int a, int b) { return a > b; });
    for (int x : deck) {
        if (!q.empty()) {
            q.push_back(q.front());
            q.pop_front();
        }
        q.push_back(x);
    }
    while (!q.empty()) {
        ans.push_back(q.back());
        q.pop_back();
    }
    return ans;
}

// 通过 | 7ms | 12.43MB
// O(n*logn) | O(n)