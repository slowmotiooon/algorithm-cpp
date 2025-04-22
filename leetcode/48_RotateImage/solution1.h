#pragma once

#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;
	int top = 0;
	int bottom = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;

	int layer = matrix.size() / 2;

	for (int t = 0; t < layer; t++) {
		for (int k = 0; k < bottom - top; k++) {
			int temp, temp2 = matrix[top][left];

			for (int i = left + 1; i <= right; i++) {
				temp = matrix[top][i];
				matrix[top][i] = temp2;
				temp2 = temp;
			}
			for (int i = top + 1; i <= bottom; i++) {
				temp = matrix[i][right];
				matrix[i][right] = temp2;
				temp2 = temp;
			}
			for (int i = right - 1; i >= left; i--) {
				temp = matrix[bottom][i];
				matrix[bottom][i] = temp2;
				temp2 = temp;
			}
			for (int i = bottom - 1; i >= top; i--) {
				temp = matrix[i][left];
				matrix[i][left] = temp2;
				temp2 = temp;
			}
		}
		top++;
		bottom--;
		left++;
		right--;
	}
}

// 运行结果：
// 通过 | 4ms | 8.79MB
// O(n^2) | O(1)
// 旋转过程为自外向内旋转
// 示例：一个4*4矩阵，先旋转最外层，再旋转最内层
//		5	1	9	11			15	13	2	5			15	13	2	5
// 
//		2	4	8	10			14	4	8	1			14	3	4	1
//						 -->					 -->					
//		13	3	6	7			12	3	6	9			12	6	8	9
// 
//		15	14	12	16			16	7	10	11			16	7	10	11