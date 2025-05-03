#pragma once

#include <vector>
using namespace std;

int combine(vector<int>& nums, int& target, int cur) {
    int ans = 0;
    for (int x : nums) {
        if (cur + x == target)
            ans++;
        else if (cur + x < target)
            ans += combine(nums, target, cur + x);
    }
    return ans;
}

int combinationSum4(vector<int>& nums, int target) {
    return combine(nums, target, 0);
}

// 超出时间限制
// "nums=[1,2,3]，target=4。可能的组合是多个，比如1+1+1+1，1+1+2等等。用这个递归的话，可能会多次计算相同的cur值。比如cur=2的时候，可能由1+1，或者2两种方式达到。这个时候，每个不同的路径都会重复计算cur=2的情况。这样就会有很多重复计算，导致时间效率低下。"
