#pragma once

#include <deque>
#include <vector>
using namespace std;

inline vector<int> mostCompetitive(vector<int>& nums, int k)
{
    deque<int> st;
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[i] < nums[st.back()]) st.pop_back();
        if (st.size() < k) st.push_back(i);
    }

    if (st.size() < k) {
        for (int i = st.front() - 1; st.size() < k; i--) st.push_front(i);
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.front());
        st.pop_front();
    }
    return ans;
}

// 解答错误。
