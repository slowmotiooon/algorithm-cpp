#pragma once

#include <vector>
using namespace std;

vector<int> findArray(vector<int>& pref) {
    vector<int> ans = { pref[0] };
    for (int i = 1; i < pref.size(); i++) ans.push_back(pref[i] ^ pref[i - 1]);
    return ans;
}

// 通过 | 82ms | 80.09MB
// O(n) | O(1)