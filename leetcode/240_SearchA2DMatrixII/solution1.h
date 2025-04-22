#pragma once

#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int i = 0;
	int j = matrix[0].size() - 1;

	while (j>=0 && i<matrix.size()) {
		if (target == matrix[i][j]) return true;
		else if (target > matrix[i][j]) i++;
		else j--;
	}
	return false;
}

// 运行结果：
// 通过 | 40ms | 17.14MB
// O(m+n) | O(1)
// 可以把矩阵看成一个斜向的二叉搜索树。有的题解中被称为“排除法”或“Z字形查找”。

vector<int> searchMatrixPlace(vector<vector<int>>& matrix, int target) {
	int i = 0;
	int j = matrix[0].size() - 1;

	while (j >= 0 && i < matrix.size()) {
		if (target == matrix[i][j]) return {i,j};
		else if (target > matrix[i][j]) i++;
		else j--;
	}
	return {-1,-1};
}