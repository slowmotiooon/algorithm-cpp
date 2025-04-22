#pragma once

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    unordered_map<int, pair<int, int>> table;
    vector<vector<int>> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            table[0] = { i, i };
            break;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') continue;
        int x = 0;
        for (int j = i; j < min((int)s.size(), i + 30); j++) {
            x = (x << 1) | (s[j] & 1);
            if (table.find(x) == table.end()) table[x] = { i, j };
        }
    }

    for (vector<int> x : queries) {
        unordered_map<int, pair<int, int>>::iterator it = table.find(x[0] ^ x[1]);
        if (it != table.end())
            ans.push_back({ it->second.first, it->second.second });
        else
            ans.push_back({ -1, -1 });
    }
    return ans;
}

// 通过 | 314ms | 120.11MB
// O(s*30+q) | O(s*30)
// 思路来自：https://leetcode.cn/problems/substring-xor-queries/solutions/2107060/yu-chu-li-suo-you-s-zhong-de-shu-zi-by-e-yxl2
// 用哈希表存储，以空间换时间。
// 说实话这道题的重点不在异或的性质，而是如何简化查询的时间复杂度。