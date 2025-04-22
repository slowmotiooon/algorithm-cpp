#pragma once

#include <algorithm>
#include <vector>
using namespace std;

long long countPairs(int n, vector<vector<int>>& edges) {
    for (vector<int>& i : edges) {
        if (i[0] > i[1]) {
            int tmp = i[0];
            i[0]    = i[1];
            i[1]    = tmp;
        }
    }
    sort(edges.begin(), edges.end());
    long long result = 0;
    int       right  = 0;
    for (int i = 0; i < n - 1; i++) {
        int current = n - 1 - i;
        while (right < edges.size() && edges[right][0] == i) {
            current--;
            right++;
        }
        result += current;
    }
    return result;
}

// 解答错误
// 本身以处理数组的方式做图的题就不对。这里是忽略了两点间接到达的情况。