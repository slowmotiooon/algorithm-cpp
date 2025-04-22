#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int rev(int x) {
    int ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> counter;
    int ans = 0;
    for (int x : nums) {
        ans += counter[x - rev(x)];
        ans %= 1000000007;
        counter[x - rev(x)]++;
    }
    return ans;
}

// 92ms | 59.19MB
// O(n*Σ) | O(1)