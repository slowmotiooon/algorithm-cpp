#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> gcdv = { {},
                             { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
                             { 1, 3, 5, 7, 9 },
                             { 1, 2, 4, 5, 7, 8 },
                             { 1, 3, 5, 7, 9 },
                             { 1, 2, 3, 4, 6, 7, 8, 9 },
                             { 1, 5, 7 },
                             { 1, 2, 3, 4, 5, 6, 8, 9 },
                             { 1, 3, 5, 7, 9 },
                             { 1, 2, 4, 5, 7, 8 } };

int countBeautifulPairs(vector<int>& nums) {
    int counter[10] = { 0 };
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int x : gcdv[nums[i] % 10]) ans += counter[x];
        int n1;
        for (int k = 1; nums[i] / k != 0; k *= 10) {
            n1 = nums[i] / k % 10;
            if (k == 1000000000) break;
        }
        counter[n1]++;
    }
    return ans;
}

// 通过 | 48ms | 76.26MB
// O(n(k+Σ)) k=10，Σ为nums[i]的平均数位长度 | O(k^2)　