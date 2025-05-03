#pragma once

#include <string>
#include <vector>
using namespace std;

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int n = s.size();
    int value[26];
    for (int i = 0; i < 26; i++) value[i] = i + 1;
    for (int i = 0; i < chars.size(); i++) value[chars[i] - 'a'] = vals[i];
    int sum = 0;
    int minSum = 0;
    int result = 0;
    for (char c : s) {
        sum += value[c - 'a'];
        if (sum - minSum > result) result = sum - minSum;
        minSum = min(minSum, sum);
    }
    return result;
}

// 通过 | 8ms | 36.56MB
// O(n+k+sigma) | O(n+sigma) 此处k是chars的大小，sigma=26