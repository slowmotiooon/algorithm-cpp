#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int diff = 0;
    int ans = 0;
    unordered_map<int, int> check;
    check[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
        diff += (nums[i] ? 1 : -1);
        if (check.find(diff) != check.end()) {
            ans = max(ans, i - check[diff]);
        }
        else
            check[diff] = i;
    }
    return ans;
}

// 通过 | 32ms | 86.39MB
// O(n) | O(n)
// 确实是前缀和.