#pragma once

#include <vector>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> sums = { 0 };
    for (int i = 0; i < arr.size(); i++) sums.push_back(sums[i] ^ arr[i]);
    vector<int> ans;
    for (vector<int> x : queries) ans.push_back(sums[x[0]] ^ sums[x[1] + 1]);
    return ans;
}

// 通过 | 208ms | 98MB
// O(n+m) | O(n)
// 前缀异或