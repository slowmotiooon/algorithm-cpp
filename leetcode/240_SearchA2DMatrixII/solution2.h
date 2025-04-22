#pragma once

#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	for (int i = 0; i < matrix.size(); i++) {
		int start = 0, end = matrix[i].size();
		if (target > matrix[i][end - 1]) continue;
		while (start < end) {
			int mid = start + (end - start) / 2;
			if (target == matrix[i][mid]) return true;
			else if (target > matrix[i][mid]) start = mid + 1;
			else end = mid;
		}
	}
	return false;
}

// 运行结果：
// 通过 | 73ms | 17.18MB
// O(m*logn) | O(1)
// 思路来自：https://leetcode.cn/problems/search-a-2d-matrix-ii/solutions/1062538/sou-suo-er-wei-ju-zhen-ii-by-leetcode-so-9hcx 方法二
// 思路为对每行进行二分查找，效率不及solution1，主要是想练习一下基本的二分查找技巧。
// 当然还有一种更慢的方法，就是遍历数组搜索 O(mn) | O(1)