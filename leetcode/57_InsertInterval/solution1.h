#pragma once

#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int front = newInterval[0], back = newInterval[1];
    for (auto& x : intervals) {
        front = min(front, x[0]);
        back = max(back, x[1]);
    }

    vector<int> diff(back + 2, 0);
    diff[newInterval[0]]++;
    diff[newInterval[1]]--;
    for (auto& x : intervals) {
        diff[x[0]]++;
        diff[x[1]]--;
    }

    int current = 0;
    vector<vector<int>> ans;
    vector<int> buffer(2);
    for (int i = 0; i < back + 2; i++) {
        if (current == 0 && diff[i] != 0) buffer[0] = i;
        if (current != 0 && current + diff[i] == 0) {
            buffer[1] = i;
            ans.emplace_back(buffer);
        }
        current += diff[i];
    }
    return ans;
}

// 解答错误
// 不能用差分做，还得用传统方法。
// 也就是找到重复区间再合并。