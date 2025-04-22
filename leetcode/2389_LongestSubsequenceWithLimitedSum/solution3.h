#pragma once


#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(),nums.end());
    partial_sum(nums.begin(), nums.end(), nums.begin()); // 原地求前缀和
    for (int& q : queries) { // 用 queries 保存答案
        q = upper_bound(nums.begin(),nums.end(), q) - nums.begin();
    }
    return queries;
}

//题解来自：https ://leetcode.cn/problems/longest-subsequence-with-limited-sum/solutions/1781111/fei-bao-li-zuo-fa-qian-zhui-he-er-fen-by-ny4m/
// 19ms | 16.07MB