#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
	sort(points.begin(), points.end());

	int left = points[0][0];
	int num = 0;

	for (int i = 0; i < points.size(); i++) {
		if (points[i][0] <= left + w) continue;
		else {
			num++;
			left = points[i][0];
		}
	}

	return num+1;
}

// 运行结果：
// 通过 | 262ms | 116.22MB
// O(n*logn) sort函数的时间复杂度是O(n*logn) | O(logn) sort函数的空间复杂度为O(logn)

// 第一次提交时好慢。
// 运行结果：
// 通过 | 2381ms | 556.89MB
// O(n*logn) | O(logn)

// 慢的原因在于第八行的排序。sort函数中使用了自定义的比较函数，导致排序时多次调用该函数，拖慢时间。
// 原代码为：sort(points.begin(), points.end(), [](vector<int> x, vector<int> y) {return x[0] < y[0]; });
// 在排序vector<vector<int>>数组时，sort函数默认依据的是其中vector<int>元素中的第一个int元素的大小，所以不用重载比较函数。