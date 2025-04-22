#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++) {
		vector<int> line;
		for (int j = 0; j < n; j++) {
			int buffer;
			cin >> buffer;
			line.push_back(buffer);
		}
		matrix.push_back(line);
	}

	cout << checkXMatrix(matrix) << endl;
	return 0;
}

// https://leetcode.cn/problems/check-if-matrix-is-x-matrix/description/		ÄÑ¶È·Ö£º1201