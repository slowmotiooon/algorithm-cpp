#pragma once

#include <vector>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<bool> a(n + 1, false), b(n + 1, false);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        a[A[i]] = true;
        b[B[i]] = true;
        int counter = 0;
        for (int i = 0; i <= n; i++)
            if (a[i] && b[i]) counter++;
        ans.push_back(counter);
    }
    return ans;
}

// 通过 | 33ms | 84.73MB
// O(n^2) | O(n)
// 这竟然能时间击败72%，内存击败56%？