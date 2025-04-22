#pragma once

#include <string>
#include <vector>
using namespace std;

bool vow(string s) {
    int n = s.size() - 1;
    return (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
           (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u');
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> counter(words.size() + 1, 0);
    for (int i = 0; i < words.size(); i++) {
        counter[i + 1] = counter[i] + vow(words[i]);
    }
    for (vector<int> x : queries) {
        ans.push_back(counter[x[1] + 1] - counter[x[0]]);
    }
    return ans;
}

// 通过 | 23ms | 70.85MB
// O(n+k) | O(n)
