#pragma once

#include <bitset>
#include <vector>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    bitset<51> a = 0, b = 0;   // 题目中最大长度为50
    bitset<51> unit = 1;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
        a |= unit << A[i];
        b |= unit << B[i];
        bitset<51> and_ = a & b;
        ans.push_back(and_.count());
    }
    return ans;
}

// 通过 | 32ms | 83.45MB
// O(n) | O(1)
// 泛用性更强的写法，可以处理长度大于64的数组。
// 并且时空复杂度完全不输前两种