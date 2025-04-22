#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	vector<vector<int>> matrix;

	for (int i = 0; i < m; i++) {
		vector<int> line;
		for (int j = 0; j < n; j++) {
			int buffer;
			cin >> buffer;
			line.push_back(buffer);
		}
		matrix.push_back(line);
	}

	vector<int> result = betterSpiralOrder(matrix);

	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}
