#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            line.push_back(b);
        }
        grid.push_back(line);
    }

    int row, col, color;
    cin >> row >> col >> color;

    vector<vector<int>> result = colorBorder(grid, row, col, color);

    for (vector<int>& x : result) {
        for (int& i : x) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/coloring-a-border/      1579