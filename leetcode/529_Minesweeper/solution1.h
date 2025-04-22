#pragma once

#include <vector>
using namespace std;

int m, n;

void dfs(vector<vector<char>>& board, int i, int j) {
    if (board[i][j] == 'B' || (board[i][j] > '0' && board[i][j] < '9')) return;

    // mark the suare with 'B' or digit
    char digit = '0';
    if (i > 0 && j > 0 && board[i - 1][j - 1] == 'M') digit++;           // topleft
    if (i > 0 && board[i - 1][j] == 'M') digit++;                        // top
    if (i > 0 && j < n - 1 && board[i - 1][j + 1] == 'M') digit++;       // topright
    if (j < n - 1 && board[i][j + 1] == 'M') digit++;                    // right
    if (i < m - 1 && j < n - 1 && board[i + 1][j + 1] == 'M') digit++;   // bottomright
    if (i < m - 1 && board[i + 1][j] == 'M') digit++;                    // bottom
    if (i < m - 1 && j > 0 && board[i + 1][j - 1] == 'M') digit++;       // bottomleft
    if (j > 0 && board[i][j - 1] == 'M') digit++;                        // left

    board[i][j] = digit == '0' ? 'B' : digit;

    // if this square has surronding mine(s), it cannot go to other squares.
    if (digit > '0') return;

    if (i > 0) dfs(board, i - 1, j);
    if (i < m - 1) dfs(board, i + 1, j);
    if (j > 0) dfs(board, i, j - 1);
    if (j < n - 1) dfs(board, i, j + 1);
    if (i > 0 && j > 0) dfs(board, i - 1, j - 1);
    if (i < m - 1 && j > 0) dfs(board, i + 1, j - 1);
    if (i > 0 && j < n - 1) dfs(board, i - 1, j + 1);
    if (i < m - 1 && j < n - 1) dfs(board, i + 1, j + 1);
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    m = board.size();
    n = board[0].size();
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    if (board[click[0]][click[1]] != 'E') return board;
    dfs(board, click[0], click[1]);
    return board;
}

// 通过 | 19ms | 15.51MB
// O(m*n) | O(m*n)
// dfs题，注意扫雷的方块视野是周围8个方块。