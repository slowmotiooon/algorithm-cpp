#pragma once

#include <string>
#include <vector>
using namespace std;

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> pre(n, -1), suf(n, -1), sum(n + 1, 0);
    int buf = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '|') buf = i;
        suf[i] = buf;
    }
    buf = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') buf = i;
        sum[i + 1] = sum[i] + (s[i] == '*');
        pre[i] = buf;
    }
    vector<int> ans;
    for (vector<int> x : queries) {
        if (suf[x[0]] == -1 || pre[x[1]] == -1)
            ans.push_back(0);
        else if (suf[x[0]] > pre[x[1]])
            ans.push_back(0);
        else
            ans.push_back(sum[pre[x[1]] + 1] - sum[suf[x[0]] + 1]);
    }
    return ans;
}

// 通过 | 97ms | 163.18MB
// O(n+q) | O(n) 准确来说是3n
// 前缀和，重点在于如何以O(1)的时间复杂度获取查询索引范围内范围最大的蜡烛位置。