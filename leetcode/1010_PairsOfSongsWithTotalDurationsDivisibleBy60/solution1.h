#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int, int> counter;
    for (int x : time) counter[x % 60]++;
    int ans = 0;
    for (int i = 0; i <= 30; i++) {
        if (i == 0 || i == 30)
            if (counter[i] & 1)
                ans += (counter[i] - 1) / 2 * counter[i];
            else
                ans += (counter[i] - 1) * (counter[i] / 2);
        else
            ans += counter[i] * counter[60 - i];
    }
    return ans;
}

// 通过 | 31ms | 31.36MB
// O(n) | O(n)