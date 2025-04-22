#pragma once

#include <set>
#include <string>
#include <vector>
using namespace std;

string clearStars(string s) {
    vector<vector<int>> astack(26);
    set<int> ban;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            ban.insert(i);
            for (int j = 0; j < 26; j++) {
                if (astack[j].empty()) continue;
                ban.insert(astack[j].back());
                astack[j].pop_back();
                break;
            }
        }
        else
            astack[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < s.size(); i++) {
        if (ban.find(i) == ban.end()) ans += s[i];
    }
    return ans;
}

// 通过 | 957ms | 191.71MB | 34:14 | 2x
// O(n*Σ) | O(n)
// 使用了26个栈
// 使用位运算优化版，利用一个整数保存26个栈的空置情况，使得查询非空的最小字母栈的时间复杂度降低为O(1)

string betterClearStars(string s) {
    vector<int> astack[26];
    int mask = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            int k = __builtin_ctz(mask);
            s[astack[k].back()] = '*';
            astack[k].pop_back();
            if (astack[k].empty()) mask ^= 1 << k;
        }
        else {
            astack[s[i] - 'a'].push_back(i);
            mask |= (1 << (s[i] - 'a'));
        }
    }
    for (char c : s)
        if (c != '*') ans += c;
    return ans;
}

// 通过 | 30ms | 23.57MB
// https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/solutions/2798240/yong-26-ge-zhan-mo-ni-pythonjavacgo-by-e-mhtn
