#pragma once

#include <bitset>
#include <vector>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    long long a = 0, b = 0;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
        a |= 1LL << A[i];
        b |= 1LL << B[i];
        ans.push_back(__builtin_popcountll(a & b));
    }
    return ans;
}

// 通过 | 31ms | 83.62MB
// O(n) | O(1)
// 位运算优化，注意对long long 类型整数的位运算处理。
