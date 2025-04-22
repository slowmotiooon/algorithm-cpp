#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int countTriplets(vector<int>& arr) {
    unordered_map<int, vector<int>> table;
    table[0].push_back(-1);
    int xor_ = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        xor_ ^= arr[i];
        table[xor_].push_back(i);
    }
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second.size() < 2) continue;
        for (int i = 1; i < it->second.size(); i++) {
            for (int j = 0; j < i; j++) {
                ans += it->second[i] - it->second[j] - 1;
            }
        }
    }
    return ans;
}

// 通过 | 0ms | 9.74MB
// O(n^2) | O(n)
// O(n^2)暴力做法，可以优化为一次循环

int betterCountTriplets(vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        int xor_ = 0;
        for (int j = i; j < arr.size(); j++) {
            xor_ ^= arr[j];
            if (xor_ == 0) ans += j - i;
        }
    }
    return ans;
}

// 通过 | 0ms | 9.11MB
// O(n^2) | O(1)
// 直接把哈希表省掉。