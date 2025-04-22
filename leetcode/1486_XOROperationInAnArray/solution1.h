#pragma once

using namespace std;

int xorOperation(int n, int start) {
    int ans = start;
    for (int i = 1; i < n; i++) {
        ans = ans ^ (start + 2 * i);
    }
    return ans;
}

// 通过 | 0ms | 7.3MB
// O(n) | O(1)
// 最基本的做法。