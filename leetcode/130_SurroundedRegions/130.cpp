#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board;
    for (int i = 0; i < m; i++) {
        vector<char> line;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            line.push_back(c);
        }
        board.push_back(line);
    }

    solve(board);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << board[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/surrounded-regions/description/