#pragma once

#include <vector>
using namespace std;

int fastPow(int x) {}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> pows = { 0 };
    for (int i = 0; i < 31; i++) {
        if (n & (1 << i)) pows.push_back(i + pows.back());
    }
    vector<int> ans;
    for (vector<int> x : queries) {
        int pow = pows[x[1] + 1] - pows[x[0]];
        int element = 1;
        for (int i = 0; i < pow; i++) element = element * 2 % 1000000007;
        ans.push_back(element);
    }
    return ans;
}

// 通过 | 268ms | 160.66MB
// O(Σ+k*pow) Σ在此处为31 | O(__builtin_popcount(n))
