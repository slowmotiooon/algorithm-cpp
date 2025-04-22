#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (vector<int>& l : matrix)
        for (int& x : l) cin >> x;
    cin >> k;

    cout << kthLargestValue(matrix, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value       1671