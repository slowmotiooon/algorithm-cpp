#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

long long beautifulSubarrays(vector<int>& nums) {
    unordered_map<int, int> counter;
    counter[0] = 1;
    int xor_ = 0;
    long long ans = 0;
    for (int x : nums) {
        xor_ ^= x;
        ans += counter[xor_];
        counter[xor_]++;
    }
    return ans;
}

// 通过 | 229ms | 121.55MB
// O(n) | O(n)
// 弱化版1442题