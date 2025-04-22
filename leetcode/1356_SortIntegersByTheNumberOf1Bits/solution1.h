#pragma once

#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortByBits(vector<int>& arr) {
    auto compare = [](int& x, int& y) {
        if (__builtin_popcount(x) < __builtin_popcount(y)) return true;
        if (__builtin_popcount(x) == __builtin_popcount(y))
            return x < y;
        else
            return false;
    };
    sort(arr.begin(), arr.end(), compare);
    return arr;
}

// 通过 | 4ms | 12.72MB
// O(n*log(n)) | O(1)
// __builtin_popcount上大分