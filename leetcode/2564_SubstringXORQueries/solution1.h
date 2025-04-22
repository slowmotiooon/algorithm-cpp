#pragma once

#include <bits/stl_algobase.h>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    vector<vector<int>> ans;
    for (vector<int> x : queries) {
        int tmp = x[0] ^ x[1];
        int l = tmp != 0 ? __lg(tmp) + 1 : 1;
        string result(l, '0');
        for (int i = 0; i < l; i++)
            if ((tmp >> i) & 1) result[l - i - 1]++;
        int place = s.find(result);
        if (place != string::npos)
            ans.push_back({ place, place + l - 1 });
        else
            ans.push_back({ -1, -1 });
    }
    return ans;
}

// 超出时间限制
// O(s*q) | O(1)