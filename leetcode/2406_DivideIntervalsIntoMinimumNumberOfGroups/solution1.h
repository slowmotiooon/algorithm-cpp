#pragma once

#include <map>
#include <vector>
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    int maxt = -1;
    for (auto& x : intervals) maxt = max(maxt, x[1]);
    vector<int> diff(maxt + 2, 0);
    for (auto& x : intervals) {
        diff[x[0]]++;
        diff[x[1] + 1]--;
    }
    int counter = 0;
    int ans = 1;
    for (int x : diff) {
        counter += x;
        ans = max(ans, counter);
    }
    return ans;
}

// 通过 | 107ms | 209.65MB | 5:59 | 2x
// O(n+l) | O(l)
// 经典差分。题目那里需要转过弯。

// 在题解
// https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/solutions/1816294/by-endlesscheng-ze3t
// 中，存在一种使用平衡树优化差分数组的方式，这样可以使差分数组的查询和增删的时间复杂度变成O(log(n))。
// 在c++中，可以使用基于红黑树或AVL树的map容器，可以有效减小区间范围过大、内容过少导致的空间开销。
// 以下是优化后的函数

int betterMinGroups(vector<vector<int>>& intervals) {
    map<int, int> diff;
    for (auto& x : intervals) {
        diff[x[0]]++;
        diff[x[1] + 1]--;
    }
    int counter = 0;
    int ans = 1;
    for (auto& x : diff) {
        counter += x.second;
        ans = max(ans, counter);
    }
    return ans;
}

// 通过 | 255ms | 119.29MB
// O(n*log(l)) | O(l)
//