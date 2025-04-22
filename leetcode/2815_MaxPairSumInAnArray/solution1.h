#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int nmax(int x) {
    int ans = 0;
    while (x != 0) {
        ans = max(ans, x % 10);
        x /= 10;
    }
    return ans;
}

int maxSum(vector<int>& nums) {
    int r[10][2] = { { 0, 0 } };
    int ans = -1;
    for (int i = 0; i < nums.size(); i++) {
        int m = nmax(nums[i]);
        if (nums[i] > r[m][0]) {
            r[m][1] = r[m][0];
            r[m][0] = nums[i];
            if (r[m][1]) ans = max(ans, r[m][0] + r[m][1]);
        }
        else if (nums[i] > r[m][1]) {
            r[m][1] = nums[i];
            ans = max(ans, r[m][0] + r[m][1]);
        }
    }
    return ans;
}

// 通过 | 23ms | 71.30MB
// O(n*sigma) sigma为数字平均数位长度 | O(1)