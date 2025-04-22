#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (vector<int>& l : grid)
        for (int& x : l) cin >> x;

    cout << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/shortest-path-in-binary-matrix/description/     1658