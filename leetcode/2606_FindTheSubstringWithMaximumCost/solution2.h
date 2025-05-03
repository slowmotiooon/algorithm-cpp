#pragma once

#include <numeric>
#include <string>
#include <vector>
using namespace std;

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int map[26];
    iota(map, map + 26, 1);
    for (int i = 0; i < chars.size(); i++) map[chars[i] - 'a'] = vals[i];
    int ans = 0, f = 0;
    for (char c : s) {
        f = max(f, 0) + map[c - 'a'];
        ans = max(ans, f);
    }
    return ans;
}