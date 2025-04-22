#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (vector<int>& l : matrix)
        for (int& x : l) cin >> x;

    cout << countSquares(matrix) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-square-submatrices-with-all-ones      1613