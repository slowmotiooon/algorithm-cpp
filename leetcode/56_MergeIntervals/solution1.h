#pragma once

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) {return x[0] < y[0]; });

	vector<vector<int>> result;

	for (int i = 0; i < intervals.size(); i++) {
		if (i == 0) {
			result.push_back(intervals[i]);
			continue;
		}

		if (intervals[i][0] <= result[result.size()-1][1]) {
			if (result[result.size() - 1][1] < intervals[i][1]) result[result.size() - 1][1] = intervals[i][1];
		}
		else result.push_back(intervals[i]);
	}

	return result;
}

// 运行结果：
// 通过 | 138ms | 50.67MB
// O(n*logn) | O(n)
// 在不排序时只能处理递增的区间数列 其他比如 [[1,4],[0,3],[2,5]] 就不能处理。
// 所以可以使用自定义的sort函数对intervals进行排序，时间复杂度是O(nlogn)，std::sort函数使用的排序方法是快速排序。