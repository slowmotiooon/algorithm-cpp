#pragma once

#include <vector>
using namespace std;

inline vector<int> mostCompetitive(vector<int>& nums, int k)
{
    vector<int> st;   // 使用vector作为栈。
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[i] < st.back() && k - st.size() < nums.size() - i) st.pop_back();
        if (st.size() < k) st.push_back(nums[i]);
    }
    return st;
}

// 通过 | 169ms | 109.69MB
// O(n) | O(n)
// 思路来自：https://leetcode.cn/problems/find-the-most-competitive-subsequence/solutions/2788312/gen-zhao-wo-guo-yi-bian-shi-li-2ni-jiu-m-36c4
// 我的思路差不多，只是不清楚如何处理遍历完nums之后st数量未达到k的时候。
