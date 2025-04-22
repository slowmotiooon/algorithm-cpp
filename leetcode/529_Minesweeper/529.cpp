#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board = vector<vector<char>>(m, vector<char>(n, '\0'));
    for (vector<char>& line : board)
        for (char& c : line) cin >> c;

    vector<int> click(2);
    cin >> click[0] >> click[1];

    vector<vector<char>> result = updateBoard(board, click);
}

// https://leetcode.cn/problems/minesweeper/description/