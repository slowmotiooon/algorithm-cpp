#pragma once

#include <vector>
using namespace std;

long long countCompleteDayPairs(vector<int>& hours) {
    int counter[24] = { 0 };
    long long ans = 0;
    for (int x : hours) {
        ans += counter[(24 - (x % 24)) % 24];
        counter[x % 24]++;
    }
    return ans;
}

// 通过 | 141ms | 135.26MB
// O(n) | O(Σ) 此处Σ=24