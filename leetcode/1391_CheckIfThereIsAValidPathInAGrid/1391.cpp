#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            line.emplace_back(c);
        }
        grid.emplace_back(line);
    }
    cout << hasValidPath(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/description/       1746