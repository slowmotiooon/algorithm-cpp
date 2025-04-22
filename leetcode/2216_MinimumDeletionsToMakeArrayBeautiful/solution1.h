#pragma once

#include <vector>
using namespace std;

int minDeletion(vector<int>& nums) {
    int n = nums.size();
    int i = 0, p = 1;
    int ans = 0;
    while (p < n) {
        if ((i + ans) % 2 == 0) {
            while (p < n && nums[i] == nums[p]) {
                p++;
                ans++;
            }
            if (p == n) return ans;
        }
        i = p;
        p++;
    }
    if (((n - ans) % 2 == 0) && n != 0) ans++;
    return ans;
}

// 解答错误
// 不知道是哪里的问题