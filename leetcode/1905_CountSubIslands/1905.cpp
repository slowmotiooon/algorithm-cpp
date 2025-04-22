#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid1;
    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            line.push_back(b);
        }
        grid1.push_back(line);
    }

    vector<vector<int>> grid2;
    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            line.push_back(b);
        }
        grid2.push_back(line);
    }

    cout << countSubIslands(grid1, grid2) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-sub-islands/description/      1679
