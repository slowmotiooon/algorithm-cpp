#pragma once

#include <vector>
using namespace std;

bool checkXMatrix(vector<vector<int>>& grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {
			if ((i == j || i + j == grid.size() - 1) && grid[i][j] == 0) return false;
			if (i != j && i + j != grid.size() - 1 && grid[i][j] != 0) return false;
		}
	}
	return true;
}

// 运行结果：
// 通过 | 25ms | 18.64MB
// O(n^2) n指矩阵的长度(宽度) | O(1)