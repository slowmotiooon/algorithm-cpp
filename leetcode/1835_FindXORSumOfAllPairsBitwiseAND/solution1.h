#pragma once

#include <vector>
using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        int a = 0, b = 0;
        for (int x : arr1)
            if ((x >> i) & 1) a++;
        for (int x : arr2)
            if ((x >> i) & 1) b++;
        ans |= ((a & 1) & (b & 1)) << i;
    }
    return ans;
}

// 通过 | 149ms | 94.05MB
// O((n+m)*log(sigma)) | O(1)