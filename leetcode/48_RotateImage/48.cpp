#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int m;
	cin >> m;

	vector<vector<int>> matrix;

	for (int i = 0; i < m; i++) {
		vector<int> line;
		for (int j = 0; j < m; j++) {
			int buffer;
			cin >> buffer;
			line.push_back(buffer);
		}
		matrix.push_back(line);
	}

	rotate(matrix);
	for (vector<int>& i : matrix) {
		for (int& j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	return 0;
}