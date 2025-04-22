#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (vector<int>& l : matrix)
        for (int& x : l) cin >> x;

    NumMatrix a(matrix);

    while (true) {
        int row1, row2, col1, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << a.sumRegion(row1, col1, row2, col2) << endl;
    }

    return 0;
}

// https://leetcode.cn/problems/range-sum-query-2d-immutable