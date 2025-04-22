#pragma once

#include <string>
using namespace std;

int maxDepth(string s) {
    int depth = 0;
    int ans = 0;
    for (char c : s) {
        if (c == '(') depth++;
        if (c == ')') depth--;
        ans = max(ans, depth);
    }
    return ans;
}

// 通过 | 1ms | 8.13MB
// O(n) | O(1)
// 如果把更新最大值的语句放在判断c=='('的条件之内，还可以优化时间