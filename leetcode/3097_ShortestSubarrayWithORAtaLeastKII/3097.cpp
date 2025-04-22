#include <iostream>
#include "solution1.h"
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int& x:nums) cin>>x;

    int k;
    cin>>k;

    cout<<minimumSubarrayLength(nums,k)<<endl;
    return 0;
}

// https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/description/        1891