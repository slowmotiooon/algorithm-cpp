#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid = vector<vector<char>>(m, vector<char>(n, 0));
    for (vector<char>& l : grid)
        for (char& x : l) cin >> x;

    cout << containsCycle(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/detect-cycles-in-2d-grid/description/