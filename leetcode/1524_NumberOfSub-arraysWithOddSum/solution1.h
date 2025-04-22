#pragma once

#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr) {
    int n = arr.size();
    vector<int> odds(n + 1, 0);
    for (int i = 0; i < n; i++) {
        odds[i + 1] = odds[i] + (arr[i] & 1);
    }
    int even = 0, odd = 0;
    for (int x : odds) {
        (x & 1 ? odd : even)++;
    }
    return (int)((long long)odd * even % (1000000007));
}

// 通过 | 19ms | 113.28MB
// O(n) | O(n)
// 只要一段子数组中有奇数个奇数，则子数组的和为奇数。
// 因此，需要求一个数组中前缀奇数和