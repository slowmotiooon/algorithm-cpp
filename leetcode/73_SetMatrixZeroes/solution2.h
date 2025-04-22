#pragma once

#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	bool r0 = false, c0 = false;

	for (int i : matrix[0]) if (i == 0) r0 = true;

	for (int i = 0; i < matrix.size(); i++) if (matrix[i][0] == 0) c0 = true;

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
		}
	}

	if (r0) for (int& i : matrix[0]) i = 0;
	if (c0) for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
}

// 运行结果：
// 通过 | 8ms | 16.49MB
// O(m*n) | O(1)
// 思路来自：https://leetcode.cn/problems/set-matrix-zeroes/solutions/670278/xiang-jie-fen-san-bu-de-o1-kong-jian-jie-dbxd