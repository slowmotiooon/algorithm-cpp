#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int countPalindromicSubsequence(string s) {
    int n = s.size();
    int ans = 0;
    vector<int> pre(n, 0), suf(n, 0);
    int has[26] = { 0 };

    for (int i = n - 2; i > 0; i--) {
        suf[i] = suf[i + 1] | (1 << (s[i + 1] - 'a'));
    }
    for (int i = 1; i < n - 1; i++) {
        pre[i] = pre[i - 1] | (1 << (s[i - 1] - 'a'));
        has[s[i] - 'a'] ^= (pre[i] & suf[i]);
    }
    for (int i = 0; i < 26; i++) {
        ans += __builtin_popcount(has[i]);
    }
    return ans;
}

// 通过 | 16ms | 21.04MB
// O(n+Σ) | O(n+Σ) Σ为字母总种类数，这里为26
// 思路来自：https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/solutions/870024/chang-du-wei-3-de-bu-tong-hui-wen-zi-xu-21trj
// 十分巧妙的一种算法，为了避免花费过多空间计算某一下标左右侧字母种类，选择通过位运算的方式存储。