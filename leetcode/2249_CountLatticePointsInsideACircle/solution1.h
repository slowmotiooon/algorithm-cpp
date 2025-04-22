#pragma once

#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int countLatticePoints(vector<vector<int>>& circles) {
	unordered_set<string> points;
	//unordered_set<pair<int, int>> points;

	for (auto i : circles) {
		for (int m = i[1] - i[2]; m <= i[1] + i[2]; m++) {
			for (int n = i[0] - i[2]; n <= i[0] + i[2]; n++) {
				pair<int, int> p = { n,m };
				int w = i[0] - n;
				int h = i[1] - m;
				if (w * w + h * h <= i[2] * i[2])
					points.insert(to_string(n)+' '+to_string(m));
			}
		}
	}
	return points.size();
}

// 通过 | 2583ms | 33.96MB
// O(n*(x+1)^2) x为圆的平均直径 | O(m) m为points数组数量
// 采用暴力枚举，利用unordered_set可以在存储已经存在的点的同时尽可能减少空间开销。
// unoredered_set不支持vector<int>, 所以我将坐标转化为字符串，导致本来就慢的时间变慢。