#pragma once

#include <vector>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    if (encoded.empty()) return {};
    vector<int> ans = { first, first ^ encoded[0] };
    for (int i = 1; i < encoded.size(); i++) {
        ans.push_back(encoded[i] ^ ans[i]);
    }
    return ans;
}

// 通过 | 19ms | 27，96MB
// O(n) | O(1)
// 实现简单，但是想到如何实现很难。