#pragma once

#include <vector>
using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    int mask = 0xffffffff << maximumBit;
    vector<int> xors = { 0 };
    vector<int> ans;
    for (int i = 0; i < n; i++) xors.push_back(xors[i] ^ nums[i]);
    for (int i = n; i > 0; i--) ans.push_back(~(xors[i] ^ mask));
    return ans;
}

// 通过 | 120ms | 104.88MB
// O(n) | O(n)
