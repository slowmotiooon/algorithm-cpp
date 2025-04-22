#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (vector<int>& line : grid)
        for (int& x : line) cin >> x;

    cout << numberOfRightTriangles(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/right-triangles     1541