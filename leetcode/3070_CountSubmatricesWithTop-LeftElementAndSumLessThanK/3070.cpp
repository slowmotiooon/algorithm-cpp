#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));
    for (vector<int>& l : grid)
        for (int& x : l) cin >> x;
    cin >> k;

    cout << countSubmatrices(grid, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k     1499