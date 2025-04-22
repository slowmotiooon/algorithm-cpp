#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> s;
    for (int x : nums) {
        if (s.count(x) && s[x] > 0) {
            ans++;
            s[x]--;
        }
        else
            s[k - x]++;
    }
    return ans;
}

// 通过 | 119ms | 67.85MB
// O(n) | O(n)