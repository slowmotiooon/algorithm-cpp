#pragma once

#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, vector<int>> counter;
    for (int i = 0; i < cards.size(); i++) {
        counter[cards[i]].push_back(i);
    }
    int ans = INT_MAX;
    for (auto it = counter.begin(); it != counter.end(); it++) {
        if (it->second.size() > 1) {
            for (int i = 1; i < it->second.size(); i++) {
                ans = min(ans, it->second[i] - it->second[i - 1] + 1);
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

// 通过 | 364ms | 164.91MB
// O(n) | O(n)