#pragma once

#include <cmath>
#include <deque>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    deque<pair<int, int>> s, j;
    int ans = 0;
    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && s.back().first < nums[i]) s.pop_back();
        while (!j.empty() && j.back().first > nums[i]) j.pop_back();
        s.push_back({ nums[i], i });
        j.push_back({ nums[i], i });
        while (s.front().first - j.front().first > limit) {
            if (s.front().second == left) s.pop_front();
            if (j.front().second == left) j.pop_front();
            left++;
        }
        ans = max(ans, i - left + 1);
    }
    return ans;
}

// 通过 | 53ms | 81.81MB
// O(n) | O(n)