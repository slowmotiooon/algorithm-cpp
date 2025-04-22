#pragma once

#include <bitset>
using namespace std;

long long minEnd(int n, int x) {
    bitset<64> ans = x;
    n -= 1;
    for (int i = 0; n != 0; i++) {
        if (n == 0) break;
        if (ans[i]) continue;
        ans[i] = n & 1;
        n >>= 1;
    }
    return ans.to_ullong();
}

// 通过 | 0ms | 8.28MB
// O(log(x)+log(n)) | O(1)
// 这真有1900分？