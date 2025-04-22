#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int countPalindromicSubsequence(string s) {
    unordered_map<char, vector<int>> index;
    for (int i = 0; i < s.size(); i++) index[s[i]].push_back(i);
    int ans = 0;
    for (auto it : index) {
        int left = it.second.front() + 1;
        int right = it.second.back();
        unordered_set<char> set;
        for (int i = left; i < right; i++) set.insert(s[i]);
        ans += set.size();
    }
    return ans;
}

// 通过 | 293ms | 31.61MB
// O(n^2) | O(n)
// 用哈希表记录每个字母所在的下标。然后再查找是否有重复字母。
// 如果有，就数两个重复字母下标间有几种字母。加起来就是答案。