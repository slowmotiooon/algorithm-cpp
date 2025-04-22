#pragma once

#include <vector>
#include <climits>
using namespace std;

int minimumSubarrayLength(vector<int>& nums, int k){
    int ans = INT_MAX;
    for(int i =0;i<nums.size();i++){
        int res = 0;
        int current = 0;
        for(int j = i;j<nums.size();j++){
            res|=nums[j];
            current++;
            if(res>=k) break;
        }
        if(res>=k) ans = min(ans,current);
    }
    return ans == INT_MAX ? -1 : ans;
}

// 超出时间限制
// O(n^2)算法，超时正常。