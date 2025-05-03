#pragma once

#include <vector>
using namespace std;

int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1, 0);
    dp[0] = 1;
    int result = 0;
    for (int i = 1; i <= high; i++) {
        for (int j = 0; j < 2; j++) {
            int place = j ? one : zero;
            if (place <= i) dp[i] = (dp[i] + dp[i - place]) % 1000000007;
        }
        if (i >= low) result = (result + dp[i]) % 1000000007;
    }
    return result;
}

// 通过 | 8ms | 11.37MB
// O(high) | O(high)
//