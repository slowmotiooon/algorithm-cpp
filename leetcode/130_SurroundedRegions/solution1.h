#pragma once

#include <vector>
using namespace std;

vector<vector<bool>> p;

void dfs(vector<vector<char>>& board, int i, int j, bool checkmode) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;

    if (checkmode)
        if (!p[i][j])
            p[i][j] = true;
        else
            return;
    else if (!p[i][j])
        board[i][j] = 'X';
    else
        return;

    dfs(board, i - 1, j, checkmode);
    dfs(board, i, j - 1, checkmode);
    dfs(board, i + 1, j, checkmode);
    dfs(board, i, j + 1, checkmode);
}

void solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        vector<bool> line(board[0].size(), false);
        p.push_back(line);
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (i != 0 && j != 0 && i != board.size() - 1 && j != board[0].size() - 1) continue;
            if (board[i][j] == 'O') dfs(board, i, j, true);
        }
    }

    for (int i = 1; i < board.size() - 1; i++) {
        for (int j = 1; j < board[0].size() - 1; j++) {
            if (board[i][j] == 'O') dfs(board, i, j, false);
        }
    }
}

// 通过 | 598ms | 23.30MB
// O(m*n) | O(m*n)