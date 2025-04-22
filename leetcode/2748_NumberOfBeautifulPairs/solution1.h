#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int countBeautifulPairs(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int n1;
        for (int k = 1; nums[i] / k != 0; k *= 10) {
            n1 = nums[i] / k % 10;
            if (k == 1000000000) break;
        }
        for (int j = i + 1; j < n; j++) {
            int n2 = nums[j] % 10;
            if (__gcd(n1, n2) == 1) ans++;
        }
    }
    return ans;
}

// 通过 | 40ms | 71.22MB
// O(n^2+nΣ) Σ为nums[i]平均数位长度 | O(1)
// 暴力解法