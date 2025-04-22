#pragma once

#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int> counter;
    int ans = INT_MAX;
    for (int i = 0; i < cards.size(); i++) {
        if (counter.find(cards[i]) != counter.end()) {
            ans = min(ans, i - counter[cards[i]] + 1);
        }
        counter[cards[i]] = i;
    }
    return ans == INT_MAX ? -1 : ans;
}

// 通过 | 236ms | 116.11MB
// O(n) | O(n)
// 优化思路: 最大值可以随着哈希表的更新而更新,从而可以优化counter的结构
// 同时把两次遍历减少到一次