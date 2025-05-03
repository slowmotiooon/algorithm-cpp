#pragma once

using namespace std;

int countHousePlacements(int n) {
    int f, f1 = 1, f2 = 1;
    for (int i = 0; i < n; i++) {
        f = (f1 + f2) % 1000000007;
        f2 = f1;
        f1 = f;
    }
    long long result = ((long long)f * f) % 1000000007;
    return result;
}

// 通过 | 0ms | 7.77MB
// O(n) | O(1)