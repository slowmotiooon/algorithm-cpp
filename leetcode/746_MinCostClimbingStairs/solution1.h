#pragma once

#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int f, f1 = 0, f2 = 0;
    for (int i = 0; i < n - 1; i++) {
        f = min(f1 + cost[i + 1], f2 + cost[i]);
        f2 = f1;
        f1 = f;
    }
    return f;
}

// 通过 | 0ms | 17.33MB
// O(n) | O(1)
// 转换函数： f(x) = min(f(x - 1) + cost[x - 1], f(x - 2) + cost[x - 2])
// 边界条件： f(1) = f(0) + cost[0], f(0) = 0