#pragma once

#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	vector<int> targetRow;
	vector<int> targetColumn;

	for (int i = 0; i < matrix.size();i++) {
		for (int j = 0; j < matrix[0].size();j++) {
			if (matrix[i][j] == 0) {
				targetRow.push_back(i);
				targetColumn.push_back(j);
			}
		}
	}

	for (int i : targetRow) {
		for (int j = 0; j < matrix[0].size(); j++) {
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j : targetColumn) {
			matrix[i][j] = 0;
		}
	}
}

// 运行结果：
// 通过 | 15ms | 16.75MB
// O(row*column) | O(row+column)
// 思路就是先找0，然后在将0所在行列置零。