#pragma once

#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int top = 0, left = 0;
	int bottom = matrix.size() - 1;
	int right = matrix[0].size() - 1;
	vector<int> result;
	int total = matrix.size() * matrix[0].size();

	while (1) {
		for (int i = left; i <= right; i++) {
			result.push_back(matrix[top][i]);
		}
		if (result.size() == total) break;
		top++;
		for (int i = top; i <= bottom; i++) {
			result.push_back(matrix[i][right]);
		}
		if (result.size() == total) break;
		right--;
		for (int i = right; i >= left; i--) {
			result.push_back(matrix[bottom][i]);
		}
		if (result.size() == total) break;
		bottom--;
		for (int i = bottom; i >= top; i--) {
			result.push_back(matrix[i][left]);
		}
		if (result.size() == total) break;
		left++;
	}
	return result;
}

// 运行结果：
// 通过 | 4ms | 8.25MB
// O(m*n) | O(1)
// 常规方法。十分直观。
// 好吧刚看了题解，常规方法是使用辅助数组模拟，这样的话空间复杂度也是O(m*n), 不如这个。
// 在这个函数中，判断是否结束的标准是result的长度是否达到matrix总数。
// 可以简化一下代码。思路不变，只是判断方式改了一下。

vector<int> betterSpiralOrder(vector<vector<int>>& matrix) {
	if (!matrix.size()) return {};	//判断非空
	vector<int> result;
	int top = 0, left = 0;
	int bottom = matrix.size() - 1;
	int right = matrix[0].size() - 1;
	

	while (1) {
		for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
		if (++top > bottom) break;	//合理利用现有变量和++，--操作。
		for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
		if (--right < left) break;
		for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
		if (--bottom < top) break;
		for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
		if (++left > right) break;
	}
	return result;
}