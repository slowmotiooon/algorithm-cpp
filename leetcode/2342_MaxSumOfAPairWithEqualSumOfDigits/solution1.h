#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int maximumSum(vector<int>& nums) {
    unordered_map<int, pair<int, int>> r;
    int ans = -1;

    for (int x : nums) {
        int s = 0;
        for (int a = x; a; a /= 10) s += a % 10;
        if (x > r[s].first) {
            r[s].second = r[s].first;
            r[s].first = x;
            if (r[s].second) ans = max(ans, r[s].first + r[s].second);
        }
        else if (x > r[s].second) {
            r[s].second = x;
            ans = max(ans, r[s].first + r[s].second);
        }
    }
    return ans;
}

// 通过 | 132ms | 62.55MB
// O(n*sigma) | O(n)