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

    cout << islandPerimeter(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/island-perimeter/description/
