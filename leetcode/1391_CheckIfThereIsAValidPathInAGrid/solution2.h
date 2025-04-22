#pragma once

#include <vector>
using namespace std;

bool hasValidPath(vector<vector<int>>& grid) {
    // if (grid.size() == 1 && grid[0].size() == 1) return true;
    int i = 0, j = 0;
    int dir  = 0;   // 0:init, 1:up, 2:down, 3:left, 4:right
    int loop = 1;
    if (grid[0][0] == 5) return false;
    if (grid[0][0] == 4) loop = 2;
    for (int x = 0; x < loop; x++) {
        i   = 0;
        j   = 0;
        dir = 0;
        while (i < grid.size() && j < grid[0].size()) {
            if (i == grid.size() - 1 && j == grid[0].size() - 1) return true;
            if (dir == 1) {
                if (grid[i][j] == 2) {
                    if (i == 0) return false;
                    if (grid[i - 1][j] != 2 && grid[i - 1][j] != 3 && grid[i - 1][j] != 4)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i--;
                        dir = 1;
                        continue;
                    }
                }
                if (grid[i][j] == 3) {
                    if (j == 0) return false;
                    if (grid[i][j - 1] != 1 && grid[i][j - 1] != 4 && grid[i][j - 1] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j--;
                        dir = 3;
                        continue;
                    }
                }
                if (grid[i][j] == 4) {
                    if (j == grid[0].size() - 1) return false;
                    if (grid[i][j + 1] != 1 && grid[i][j + 1] != 3 && grid[i][j + 1] != 5)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j++;
                        dir = 4;
                        continue;
                    }
                }
            }
            if (dir == 2) {
                if (grid[i][j] == 2) {
                    if (i == grid.size() - 1) return false;
                    if (grid[i + 1][j] != 2 && grid[i + 1][j] != 5 && grid[i + 1][j] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i++;
                        continue;
                    }
                }
                if (grid[i][j] == 5) {
                    if (j == 0) return false;
                    if (grid[i][j - 1] != 1 && grid[i][j - 1] != 4 && grid[i][j - 1] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j--;
                        dir = 3;
                        continue;
                    }
                }
                if (grid[i][j] == 6) {
                    if (j == grid[0].size() - 1) return false;
                    if (grid[i][j + 1] != 1 && grid[i][j + 1] != 3 && grid[i][j + 1] != 5)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j++;
                        dir = 4;
                        continue;
                    }
                }
            }
            if (dir == 3) {
                if (grid[i][j] == 1) {
                    if (j == 0) return false;
                    if (grid[i][j - 1] != 1 && grid[i][j - 1] != 4 && grid[i][j - 1] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j--;
                        continue;
                    }
                }
                if (grid[i][j] == 4) {
                    if (i == grid.size() - 1) return false;
                    if (grid[i + 1][j] != 2 && grid[i + 1][j] != 5 && grid[i + 1][j] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i++;
                        dir = 2;
                        continue;
                    }
                }
                if (grid[i][j] == 6) {
                    if (i == 0) return false;
                    if (grid[i - 1][j] != 2 && grid[i - 1][j] != 3 && grid[i - 1][j] != 4)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i--;
                        dir = 1;
                        continue;
                    }
                }
            }
            if (dir == 4) {
                if (grid[i][j] == 1) {
                    if (j == grid[0].size() - 1) return false;
                    if (grid[i][j + 1] != 1 && grid[i][j + 1] != 3 && grid[i][j + 1] != 5)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j++;
                        continue;
                    }
                }
                if (grid[i][j] == 3) {
                    if (i == grid.size() - 1) return false;
                    if (grid[i + 1][j] != 2 && grid[i + 1][j] != 5 && grid[i + 1][j] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i++;
                        dir = 2;
                        continue;
                    }
                }
                if (grid[i][j] == 5) {
                    if (i == 0) return false;
                    if (grid[i - 1][j] != 2 && grid[i - 1][j] != 3 && grid[i - 1][j] != 4)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i--;
                        dir = 1;
                        continue;
                    }
                }
            }
            if (dir == 0) {
                if (grid[i][j] == 1 || grid[i][j] == 6) {
                    if (grid[i][j + 1] != 1 && grid[i][j + 1] != 3)
                        return false;
                    else {
                        grid[i][j] = 0;
                        j++;
                        dir = 4;
                        continue;
                    }
                }
                if (grid[i][j] == 2 || grid[i][j] == 3) {
                    if (grid[i + 1][j] != 2 && grid[i + 1][j] != 6)
                        return false;
                    else {
                        grid[i][j] = 0;
                        i++;
                        dir = 2;
                        continue;
                    }
                }
                if (grid[i][j] == 4) {
                    if (grid[i][j + 1] == 1 && grid[i][j + 1] == 3) {
                        grid[i][j] = 0;
                        j++;
                        dir = 4;
                        continue;
                    }
                    else if (grid[i + 1][j] == 2 && grid[i + 1][j] == 6) {
                        grid[i][j] = 0;
                        i++;
                        dir = 2;
                        continue;
                    }
                    else
                        return false;
                }
            }
        }
    }
    return false;
}

// 纯迭代，不知道怎么回事segmentation fault了