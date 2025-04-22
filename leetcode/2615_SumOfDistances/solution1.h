#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<long long>> sums;
    for (int i = 0; i < n; i++) {
        if (sums.find(nums[i]) != sums.end()) {
            sums[nums[i]].push_back(sums[nums[i]].back() + i);
        }
        else {
            sums[nums[i]] = { 0, i };
        }
    }
    vector<long long> ans(n);
    for (auto s : sums) {
        if (s.second.size() < 3) continue;
        for (int i = 1; i < s.second.size(); i++) {
            long long place = s.second[i] - s.second[i - 1];
            long long res =
                (s.second[s.second.size() - 1] - s.second[i]) - place * (s.second.size() - 1 - i);
            res += place * (i - 1) - (s.second[i - 1] - s.second[0]);
            ans[place] = res;
        }
    }
    return ans;
}

// 通过 | 83ms | 117.46MB
// O(n) | O(n)
// 通过是通过了，不过就是有些别扭