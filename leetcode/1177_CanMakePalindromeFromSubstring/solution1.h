#pragma once

#include <string>
#include <vector>
using namespace std;

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int l = s.size(), n = queries.size();
    vector<int> alp(l + 1, 0);
    for (int i = 0; i < l; i++) {
        alp[i + 1] = alp[i] ^ (1 << (s[i] - 'a'));
    }
    vector<bool> ans;
    for (vector<int> q : queries) {
        int current = alp[q[1] + 1] ^ alp[q[0]];
        int minSteps = __builtin_popcount(current) / 2;
        ans.push_back(q[2] >= minSteps);
    }
    return ans;
}

// 通过 | 51ms | 104.29MB
// O(l+n) | O(l)
// 应该是最优的方法了。形成回文串的基础是字符串中最多0个（长度为偶数）？1个（长度为奇数）字母出现的次数为偶数。
// 而涉及到判断字母出现次数的奇偶性，可以通过位运算来减少空间复杂度。