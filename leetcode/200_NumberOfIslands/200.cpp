#include "solution1.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid;
    for (int i = 0; i < m; i++) {
        vector<char> line;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            line.emplace_back(c);
        }
        grid.emplace_back(line);
    }
    cout << numIslands(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/number-of-islands/description/
