#pragma once

#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int>> d;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        while (!d.empty() && d.back().first <= nums[i]) d.pop_back();
        d.push_back({ nums[i], i });
        if (i < k - 1) continue;
        while (d.front().second <= i - k) d.pop_front();
        ans.push_back(d.front().first);
    }
    return ans;
}

// 通过 | 48ms | 138.13MB
// O(n) | O(n)
// 使用了单调双端队列
// 视频讲解： https://www.bilibili.com/video/BV1bM411X72E/