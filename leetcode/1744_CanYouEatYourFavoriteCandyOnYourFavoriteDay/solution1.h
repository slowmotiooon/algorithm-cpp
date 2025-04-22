#pragma once

#include <vector>
using namespace std;

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    int n = candiesCount.size();
    int k = queries.size();
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + candiesCount[i];
    }
    vector<bool> ans;
    for (vector<int> x : queries) {
        ans.push_back(x[1] < sum[x[0] + 1] && (long long)x[2] * (x[1] + 1) > sum[x[0]]);
    }
    return ans;
}

// 通过 | 47ms | 130.89MB
// O(n+k) | O(n)
// 至于为什么15行65列处是(x[1]+1)， 见题解：
// https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/solutions/806205/gong-shui-san-xie-qian-zhui-he-qiu-jie-c-b38y
