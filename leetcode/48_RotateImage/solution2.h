#pragma once

#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;
	int tmp;
	int n = matrix.size();

	for (int i = 0; i < n / 2 + n % 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			tmp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}
	}
}

// 运行结果：
// 通过 | 0ms | 8.76MB
// O(n^2) | O(1)
// 思路来自：https://leetcode.cn/problems/rotate-image/solutions/1228078/48-xuan-zhuan-tu-xiang-fu-zhu-ju-zhen-yu-jobi