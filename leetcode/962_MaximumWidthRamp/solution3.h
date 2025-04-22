#pragma once

#include <vector>
#include <algorithm>
using namespace std;


int maxWidthRamp(vector<int>& nums) {
    vector<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (st.empty() || nums[st.back()] > nums[i]) {//要把第一个数据push
            st.push_back(i);
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[i] >= nums[st.back()]) {
            ans = max(ans, i - st.back());
            st.pop_back();
        }
    }
    return ans;
}

// 题解来自：https://leetcode.cn/problems/maximum-width-ramp/solutions/2841069/cdan-diao-zhan-zhu-shi-by-ysmagixgds-p7o2
// 不是很能理解。