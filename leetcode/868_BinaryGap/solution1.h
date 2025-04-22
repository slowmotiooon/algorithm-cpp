#pragma once

using namespace std;

int binaryGap(int n) {
    if (__builtin_popcount(n) <= 1) return 0;
    int count = 0;
    int ans = -1;
    while (n > 0) {
        if ((n & 1) == 1) {
            if (count > ans) ans = count;
            count = 0;
        }
        n = n >> 1;
        if (ans != -1) count++;
    }
    return ans;
}

// 通过 | 4ms | 7.45MB
// O(log(n)) | O(1)